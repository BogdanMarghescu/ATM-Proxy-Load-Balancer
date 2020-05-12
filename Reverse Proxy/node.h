#pragma once
#include <string>
#include <iostream>

namespace ReverseProxy
{
    class Node
    {
    protected:
        int socket;
        std::string ip;
        int port;

    public:
        void setIp(std::string ip) { this->ip = ip; }
        void setPort(int port) { this->port = port; }
        void setSocket(int socket) { this->socket = socket; }

        std::string getIp() { return ip; }
        int getPort() { return port; }
        int getSocket() { return socket; }

        virtual void display()
        {
            std::cout << "Socket " << socket << ": " << ip << ":" << port << std::endl;
        }
    }; 
}