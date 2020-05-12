#pragma once
#include "balancing_algoritm.h"

namespace ReverseProxy
{
    class AlgorithmGenerator
    {
    public:
        static BalancingAlgorithm*          generate_RoundRobin();
        static BalancingAlgorithm*          generate_IpHashing();
        static BalancingAlgorithm*          generate_LeastConnections();
    };
}
