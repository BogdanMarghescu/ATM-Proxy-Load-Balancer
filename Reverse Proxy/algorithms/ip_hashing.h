#pragma once
#include "balancing_algoritm.h"

namespace ReverseProxy
{
    class IpHashing : public BalancingAlgorithm
    {
    public:
        IpHashing() : BalancingAlgorithm(2) {}
        Server*                         chooseServer();
    };  
}