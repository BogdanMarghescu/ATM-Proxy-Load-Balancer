#include "info.h"
#include "../load_balancer.h"

using namespace ReverseProxy;

void Info::solve()
{
    LoadBalancer &load_balancer = LoadBalancer::getInstance();
    response = load_balancer.getServersInfo();
}