#include "Request_Generator.h"
#include "requests_handler.h"
#include "request.h"
#include "../load_balancer.h"
#include "../Base64.h"
#include <iostream>
#include <sys/socket.h>

using namespace ReverseProxy;

void RequestsHandler::addRequest(char *buffer)
{

    LoadBalancer &instance = LoadBalancer::getInstance();
    Logger &logger = Logger::getInstance();
    Request *to_add;
    char *temp;

    std::string rawCode = buffer;
    temp = strtok(buffer, " \0");

    // False request
    if (temp == nullptr)
        return;

    // Get the type of the request and parse the tags
    if (!strcmp(temp, "INFO"))
        to_add = RequestGenerator::generate_INFO_REQUEST();
    else if (!strcmp(temp, "TASK"))
    {
        char *p;
        int type, arg_1, arg_2;

        p = strtok(NULL, " ");
        if (p)
            type = atoi(p);
        else
            return;

        p = strtok(NULL, " ");
        if (p)
            arg_1 = atoi(p);
        else
            return;

        switch (type)
        {
        case 1: // Factorial
            to_add = RequestGenerator::generate_FACTORIAL_REQUEST(arg_1);
            break;
        case 2: // Power
            p = strtok(NULL, " \0");
            if (p)
                arg_2 = atoi(p);
            else
                return;

            to_add = RequestGenerator::generate_POWER_REQUEST(arg_1, arg_2);
            break;
        case 3: // Root
            p = strtok(NULL, " \0");
            if (p)
                arg_2 = atoi(p);
            else
                return;
            to_add = RequestGenerator::generate_ROOT_REQUEST(arg_1, arg_2);
            break;
        default:
            return;
        }
    }
    else if (!strcmp(temp, "ALG"))
    {
        char *p;
        int id;

        p = strtok(NULL, " \0");
        if (p)
            id = atoi(p);
        else
            return;
        if (id > 3)
            return;
        to_add = RequestGenerator::generate_ALG_REQUEST(id);
    }
    else if (!strcmp(temp, "AUTH"))
    {
        std::string user, pass;
        char *p;

        p = strtok(NULL, " ");
        if (p)
            user = p;
        else
            return;
        p = strtok(NULL, " \0");
        if (p)
            pass = p;
        else
            return;

        to_add = RequestGenerator::generate_AUTH_REQUEST(user, pass);
    }
    else if (!strcmp(temp, "CREATE_USER"))
    {
        std::string user, pass;
        char *p;

        p = strtok(NULL, " ");
        if (p)
            user = p;
        else
            return;
        p = strtok(NULL, " \0");
        if (p)
            pass = p;
        else
            return;

        to_add = RequestGenerator::generate_CREATEUSER_REQUEST(user, pass);
    }
    else if (!strcmp(temp, "LOGOUT"))
        to_add = RequestGenerator::generate_LOGOUT_REQUEST();
    else
    {
        return;
    }

    to_add->rawCode = rawCode;

    std::unique_lock<std::mutex> locker(instance.mutex);
    if (to_add->identifier != -1)
        logger << "Added Request #" + std::to_string(to_add->identifier) + " with raw code \"" + to_add->rawCode + "\"";
    requests.push_back(to_add);
    locker.unlock();
    instance.cond_var.notify_one(); // Signal the thread that a request has come
}

void RequestsHandler::addResponse(char *buffer, Server &from)
{
    LoadBalancer &instance = LoadBalancer::getInstance();
    Logger &logger = Logger::getInstance();
    std::unique_lock<std::mutex> locker(instance.mutex);

    if ((buffer[0] >= 48) && (buffer[0] <= 57)) // TASK
    {
        int identifier = atoi(strtok(buffer, " "));
        auto it = requests.begin();
        for(;it!=requests.end();it++)
            if(identifier == (*it)->identifier)
                break;
        if(it == requests.end())
            {
                locker.unlock();
                return;
            }

        (*it)->response = "TASK ";
        (*it)->response.append(strtok(NULL, "\n"));
        (*it)->response.append(" (from " + from.getIp() + ")");
        logger << "Added a response for Request #" + std::to_string((*it)->identifier) + ". Response: " << (*it)->response;
    }
    else // INFO
    {
        strtok(buffer, " ");
        // go after "INFO"
        if (atoi(strtok(NULL, " "))) // Server is UP
        {
            from.up = true;
        }
        else // Server is DOWN
        {
            from.up = false;
        }

        from.load = (float)atof(strtok(NULL, " "));
        from.threads_available = 5 - (int)from.load / 20;
        from.hits = atoi(strtok(NULL, " \r"));
    }
    locker.unlock();
    this->responseFilled.notify_one();
}

void RequestsHandler::sendResponses()
{
    LoadBalancer &instance = LoadBalancer::getInstance();
    User &client = User::getInstance();
    Logger &logger = Logger::getInstance();
    while (true)
    {
        std::unique_lock<std::mutex> locker(instance.mutex);
        responseFilled.wait(locker, [this]() { return !!(this->dequeueResponseToSend()); });

        Request *to_send = this->dequeueResponseToSend();
        if (to_send != nullptr)
        {
            std::string sendBuffer = Base64::getInstance().encode(to_send->response);
            int sentBytes = send(client.getSocket(), sendBuffer.c_str(), sendBuffer.size() + 1, 0);
            if (sentBytes == -1)
            {
                requests.erase(std::find(requests.begin(), requests.end(), to_send));
                locker.unlock();
                return;
            }
            if (to_send->type != INFO)
            {
                std::cout << "Sending \"" << to_send->response.c_str() << "\"" << std::endl;
                logger << "Sent response to client: \"" + to_send->response + "\"";
            }
            requests.erase(std::find(requests.begin(), requests.end(), to_send));
            if (to_send->identifier != -1)
                logger << "Request #" + std::to_string(to_send->identifier) + " erased.";
        }
        locker.unlock();
    }
}

void RequestsHandler::solveRequests()
{
    LoadBalancer &instance = LoadBalancer::getInstance();
    User &client = User::getInstance();
    Logger &logger = Logger::getInstance();

    while (true)
    {
        std::unique_lock<std::mutex> locker(instance.mutex);
        instance.cond_var.wait(locker, [this]() { return !!requests.size(); });
        Request *to_solve = this->dequeueRequestToSolve();

        if (to_solve != nullptr)
        {
            if (client.isLoggedIn())
            {
                switch (to_solve->type)
                {
                case TASK:
                {
                    std::string buffer = std::to_string(to_solve->identifier);
                    buffer.append(" " + to_solve->rawCode);

                    BalancingAlgorithm::nextServer = instance.algorithms[instance.client.getAlgorithm() - 1]->chooseServer();
                    if (BalancingAlgorithm::nextServer == nullptr)
                    {
                        to_solve->response = "TASK No available server at the moment!";
                        to_solve->sentToServer = true;
                    }
                    else
                    {
                        int serverSocket = BalancingAlgorithm::nextServer->getSocket();
                        std::string to_send = Base64::getInstance().encode(buffer);
                        send(serverSocket, to_send.c_str(), to_send.size() + 1, 0);
                        std::cout << "I have sent \"" << buffer << "\" to " << BalancingAlgorithm::nextServer->ip << std::endl;
                        logger << "I have sent \"" + buffer + "\" to " + BalancingAlgorithm::nextServer->ip;
                        to_solve->sentToServer = true;
                    }

                    responseFilled.notify_one();
                    break;
                }
                case ALG:
                    to_solve->solve();
                    responseFilled.notify_one();
                    break;
                case INFO:
                    to_solve->solve();
                    responseFilled.notify_one();
                    break;
                case LOGOUT:
                {
                    to_solve->solve();
                    this->requests.erase(std::find(requests.begin(), requests.end(), to_solve));
                    break;
                }
                case CREATE_USER:
                    this->requests.erase(std::find(requests.begin(), requests.end(), to_solve));
                    break;
                case AUTH:
                    this->requests.erase(std::find(requests.begin(), requests.end(), to_solve));
                    break;
                }
            }
            else
            {
                switch (to_solve->type)
                {
                case AUTH:
                    to_solve->solve();
                    responseFilled.notify_one();
                    break;
                case CREATE_USER:
                    to_solve->solve();
                    responseFilled.notify_one();
                    break;
                default:
                    this->requests.erase(std::find(requests.begin(), requests.end(), to_solve));
                    break;
                }
            }
            if (to_solve->identifier != -1)
                logger << "Request #" + std::to_string(to_solve->identifier) + " solved.";
        }

        locker.unlock();
    }
}

Request *RequestsHandler::dequeueResponseToSend()
{
    if (requests.size() == 0)
    {
        return nullptr;
    }

    for (auto it = requests.begin(); it != requests.end(); it++)
    {
        if (!(*it)->response.empty())
            return (*it);
    }
    return nullptr;
}

Request *RequestsHandler::dequeueRequestToSolve()
{
    if (requests.size() == 0)
    {
        return nullptr;
    }

    for (auto it = requests.begin(); it != requests.end(); it++)
    {
        if (((*it)->type != TASK) && (*it)->response.empty())
            return *it;
        if (((*it)->type == TASK) && ((*it)->sentToServer == false))
            return *it;
    }
    return nullptr;
}

void RequestsHandler::print()
{
    LoadBalancer &instance = LoadBalancer::getInstance();

    std::unique_lock<std::mutex> locker(instance.mutex);
    for (auto i : requests)
    {
        std::cout << i->identifier << " " << i->type << " " << std::endl;
    }
    locker.unlock();
}
