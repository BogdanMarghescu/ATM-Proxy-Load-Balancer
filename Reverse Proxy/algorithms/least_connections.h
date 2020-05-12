#pragma once
#include "balancing_algoritm.h"

namespace ReverseProxy
{
    class LeastConnections : public BalancingAlgorithm
    {
    public:
        LeastConnections() : BalancingAlgorithm(3) {}
        Server*                     chooseServer();
    };  
}