#include "round_robin.h"

using namespace ReverseProxy;

Server *RoundRobin::chooseServer()
{
    if (servers == nullptr)
        return nullptr;
    if (servers->size() == 0)
        return nullptr;

    if (nextServer == nullptr) // No server has yet been selected
    {
        for (auto it = servers->begin(); it != servers->end(); it++)
        {
            if ((it->getStatus() == true) && (it->getLoad() < 100))
            {
                BalancingAlgorithm::nextServer = &(*it);
                return &(*it);
            }
        }
        return nullptr;         // No server available
    }

    auto it = servers->begin();
    while (&(*it) != BalancingAlgorithm::nextServer) // Find current last server put to work
    {
        it++;
    }
    int serversNb = servers->size();

    while (--serversNb) // Choose the next one according to RR
    {
        it++;
        if (it == servers->end())
            it = servers->begin();
        if (it->getStatus() == true)
            break;
    }
    if (it->getLoad() == 100) // All servers are full
        return nullptr;

    BalancingAlgorithm::nextServer = &(*it);
    return &(*it);
}