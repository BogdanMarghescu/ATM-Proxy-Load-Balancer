#include "server.h"
#include <cstdlib>

using namespace ReverseProxy;

void Server::setStatus(bool status)
{
    up = status;
}

bool Server::getStatus()
{
    return up;
}

std::string Server::getInfo()
{
    return this->ip + " " + std::to_string(up) + " " + std::to_string(load) + " " + std::to_string(hits);
}

float Server::getLoad()
{
    return load;
}