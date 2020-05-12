#include <iostream>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fstream>
#include <cerrno>
#include "server.h"
#include "load_balancer.h"
#include "exceptions/server_not_bound.h"
#include "exceptions/server_not_listening.h"
#include "exceptions/server_not_accepting.h"
#include "exceptions/failed_select.h"
#include "exceptions/timeout_select.h"
#include "exceptions/failed._recv.h"
#include "exceptions/failed_send.h"
#include "requests/requests_handler.h"
#include "Base64.h"

#define MAX_CONN 1
#define CLIENT_PORT 54001
#define SERVER_PORT 54000

using namespace ReverseProxy;

LoadBalancer *LoadBalancer::instance = nullptr;
Server *BalancingAlgorithm::nextServer = nullptr;
std::list<Server> *BalancingAlgorithm::servers = nullptr;

LoadBalancer &LoadBalancer::getInstance()
{
    if (instance == nullptr)
    {
        instance = new LoadBalancer;
    }
    return *instance;
}

void LoadBalancer::destroyInstance()
{
    if (instance != nullptr)
        delete instance;
}

LoadBalancer::LoadBalancer()
{
    my_socket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server_address;

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(CLIENT_PORT);
    server_address.sin_addr.s_addr = INADDR_ANY; // accept connections on all intefaces

    try
    {
        if (bind(my_socket, (sockaddr *)&server_address, sizeof(server_address)) == 0)
            std::cout << "Server succesfully bound! " << std::endl;
        else
            throw server_not_bound();

        if (listen(my_socket, MAX_CONN) == 0)
            std::cout << "Server listening for clients on port " << htons(server_address.sin_port) << " ...\n";
        else
            throw server_not_listening();
    }
    catch (server_not_listening &e)
    {
        std::cerr << e.what() << std::endl;
        logger << ErrorFlag() << e.what();
        close(my_socket);
        exit(-1);
    }
    catch (server_not_bound &e)
    {
        std::cerr << e.what() << std::endl;
        logger << ErrorFlag() << e.what();
        close(my_socket);
        exit(-1);
    }

    algorithms.push_back(AlgorithmGenerator::generate_RoundRobin());
    algorithms.push_back(AlgorithmGenerator::generate_IpHashing());
    algorithms.push_back(AlgorithmGenerator::generate_LeastConnections());

    logger << "Load Balancer started.";

    this->inputServers();
    this->checkServersAvailability();
}

LoadBalancer::~LoadBalancer()
{
    close(my_socket);
    close(client.getSocket());

    for (auto it = servers.begin(); it != servers.end(); it++)
        close(it->getSocket());

    std::cout << "Server closed.\n";
}

void LoadBalancer::inputServers()
{
    std::ifstream file;
    std::string ip;

    file.open("servers.txt", std::ios::in);

    while (!file.eof())
    {
        std::getline(file, ip);
        Server to_add;
        to_add.setIp(ip);
        servers.push_back(to_add);
    }

    logger << std::to_string(servers.size()) + " servers read from servers.txt";
}

void LoadBalancer::checkServersAvailability()
{
    FD_ZERO(&ready_sockets);
    FD_ZERO(&current_sockets);

    BalancingAlgorithm::servers = &(this->servers);

    for (auto it = servers.begin(); it != servers.end(); it++)
    {
        int sock = socket(AF_INET, SOCK_STREAM, 0);

        sockaddr_in address;
        address.sin_family = AF_INET;
        address.sin_port = htons(SERVER_PORT);
        address.sin_addr.s_addr = inet_addr(it->getIp().c_str());

        std::cout << "Connecting to " << inet_ntoa(address.sin_addr) << " ...\n";
        int var = connect(sock, (sockaddr *)&address, sizeof(address));

        if (var == 0)
        {
            std::cout << "Connected succesfully to " << inet_ntoa(address.sin_addr) << std::endl;
            logger << "Connected succesfully to " << inet_ntoa(address.sin_addr);
            it->setStatus(true);
            FD_SET(sock, &current_sockets); // Add the socket to the fd_set
        }
        else
        {
            std::cout << "Failed to connect to " << it->getIp() << std::endl;
            logger << ErrorFlag() << "Failed to connect to " << it->getIp();
        }

        it->setPort(SERVER_PORT);
        it->setSocket(sock);
    }
}

void LoadBalancer::requestServersInfo()
{

    int rc;
    try
    {
        while (true)
        {
            std::unique_lock<std::mutex> locker(server_mutex);
            for (auto it = servers.begin(); it != servers.end(); it++)
            {
                if (it->getStatus())
                {
                    std::string to_send = Base64::getInstance().encode("INFO");
                    rc = send(it->getSocket(), to_send.c_str(), to_send.size() + 1, 0);
                    if (rc == -1)
                    {
                        std::cout << it->getIp() << " went down.";
                        logger << it->getIp() << " went down.";
                        it->setStatus(false);
                        throw failed_send();
                    }
                }
            }
            locker.unlock();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    catch (failed_send &e)
    {
        std::cerr << e.what() << '\n';
        logger << ErrorFlag() << e.what();
    }

    std::cout << "Nu ar trebui sa ma execut!\n";
}

std::string LoadBalancer::getServersInfo()
{
    std::string response = "INFO";

    for (auto it = servers.begin(); it != servers.end(); it++)
    {
        response.append("\n");
        response.append(it->getInfo());
    }
    return response;
}

void LoadBalancer::waitForRequests()
{
    int sock = client.getSocket();
    char buffer[1024];
    std::cout << "I am waiting for requests...\n";
    logger << "Waiting for requests...";

    while (true)
    {
        memset(buffer, 0, 1024);
        int bytesRecv = recv(sock, buffer, 1024, 0);
        if ((bytesRecv == 0) || (bytesRecv == -1)) // User closed the connection
        {
            std::cout << "User disconnected.\n";
            logger << "User disconnected.";
            if ((this->client.isLoggedIn())) // If user quit unexpectedly
            {
                client.deauthenticate();
            }
            std::thread waitUser(&LoadBalancer::waitNewUser, this);
            waitUser.detach();
            return;
        }
        if (strlen(buffer) == 0)
            continue;
        std::string to_add = Base64::getInstance().decode(buffer);
        if (to_add.rfind("INFO") == std::string::npos)
        {
            std::cout << "User sent ... " << to_add << std::endl;
            logger << "User sent \"" + std::string(to_add) + "\"";
        }
        req_handler.addRequest((char *)to_add.c_str());
    }
}

void LoadBalancer::waitForResponses()
{
    char buffer[4096];
    int length;

    int sock;

    try
    {
        while (true)
        {
            int rc;
            ready_sockets = current_sockets;
            rc = select(FD_SETSIZE, &ready_sockets, NULL, NULL, NULL);
            if (rc == -1)
                throw failed_select();
            if (rc == 0)
                throw timeout_select();

            for (auto it = servers.begin(); it != servers.end(); it++)
            {
                sock = it->getSocket();
                if (FD_ISSET(sock, &ready_sockets))
                {
                    memset(buffer, 0, 4096);
                    rc = recv(sock, buffer, 4096, 0);
                    if (rc == -1)
                    {
                        std::cout << "Server " << it->getIp() << " disconnected abnormally.\n";
                        logger << "Server" + it->getIp() + " disconnected abnormally.";
                        it->setStatus(false);
                        close(sock);
                        FD_CLR(sock, &current_sockets);
                    }
                    if (rc == 0)
                    {
                        std::cout << "Server " << it->getIp() << " disconnected normally.\n";
                        logger << "Server" + it->getIp() + " disconnected normally.";
                        it->setStatus(false);
                        close(sock);
                        FD_CLR(sock, &current_sockets);
                    }
                    if (rc > 0)
                    {
                        std::string to_add = Base64::getInstance().decode(buffer);
                        if (to_add.rfind("INFO") == std::string::npos)
                            std::cout << "Received from server : " << to_add << std::endl;
                        req_handler.addResponse((char *)to_add.c_str(), *it);
                    }
                }
            }
        }
    }
    catch (failed_select &e)
    {
        std::cerr << e.what() << '\n';
        logger << ErrorFlag() << e.what();
        //exit(-1);
    }
    catch (timeout_select &e)
    {
        std::cerr << e.what() << '\n';
        logger << ErrorFlag() << e.what();
        exit(-1);
    }
}

void LoadBalancer::waitNewUser()
{
    int client_socket;
    sockaddr_in client_address;
    socklen_t address_length = sizeof(client_address);

    char buffer[1024];

    std::cout << "Waiting for somebody to connect...\n";
    logger << "Waiting for somebody to connect...";
    try
    {
        client_socket = accept(my_socket, (sockaddr *)&client_address, &address_length);

        if (client_socket > 0)
        {
            std::cout << inet_ntoa(client_address.sin_addr) << " connected.\n";
            logger << std::string(inet_ntoa(client_address.sin_addr)) + " connected.";

            client.setIp(inet_ntoa(client_address.sin_addr));
            client.setPort(CLIENT_PORT);
            client.setSocket(client_socket);
        }
        else
        {
            throw server_not_accepting();
        }
    }
    catch (server_not_accepting &e)
    {
        std::cerr << e.what() << " " << errno << std::endl;
        logger << ErrorFlag() << e.what();
        exit(-1);
    }

    std::thread waitRequests(&LoadBalancer::waitForRequests, this);
    waitRequests.detach();
}

void LoadBalancer::start()
{
    this->waitNewUser();
    std::thread responses(&LoadBalancer::waitForResponses, this);
    std::thread sendResponses(&RequestsHandler::sendResponses, std::ref(this->req_handler));
    std::thread solver(&RequestsHandler::solveRequests, std::ref(this->req_handler));
    responses.detach();
    sendResponses.detach();
    solver.detach();

    this->requestServersInfo();
}