#include <iostream>
#include "load_balancer.h"



int main()
{
    ReverseProxy::LoadBalancer& load_balancer = ReverseProxy::LoadBalancer::getInstance();
    load_balancer.start();
    ReverseProxy::LoadBalancer::destroyInstance();
    
    return 0;
}
