#include "Algortihm_Generator.h"
#include "round_robin.h"
#include "ip_hashing.h"
#include "least_connections.h"

using namespace ReverseProxy;

BalancingAlgorithm *AlgorithmGenerator::generate_RoundRobin()
{
    return new RoundRobin();
}

BalancingAlgorithm *AlgorithmGenerator::generate_IpHashing()
{
    return new IpHashing();
}

BalancingAlgorithm *AlgorithmGenerator::generate_LeastConnections()
{
    return new LeastConnections();
}