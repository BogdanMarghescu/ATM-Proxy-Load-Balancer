#include "least_connections.h"

using namespace ReverseProxy;

Server *LeastConnections::chooseServer()
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
    auto to_return = servers->begin();

    float leastLoad = to_return->getLoad();

    for (auto it = servers->begin(); it != servers->end(); it++)
    {
        if (it->getLoad() < leastLoad)
        {
            to_return = it;
            leastLoad = it->getLoad();
        }
    }

    if(leastLoad == 100)
        return nullptr;

    return &(*to_return);
}