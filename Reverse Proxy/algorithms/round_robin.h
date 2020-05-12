#pragma once
#include "balancing_algoritm.h"

namespace ReverseProxy
{
    class RoundRobin : public BalancingAlgorithm
    {

    public:
        RoundRobin() : BalancingAlgorithm(1) {}
        Server*                     chooseServer();
    };  
}