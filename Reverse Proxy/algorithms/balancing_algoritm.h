#pragma once
#include <list>
#include "ibalancing_algorithm.h"

namespace ReverseProxy
{
    class BalancingAlgorithm : public iBalancingAlgorithm
    {
        int                             id;

    public:
        static Server*                  nextServer;
        static std::list<Server>*       servers;

        BalancingAlgorithm(int id) : id(id) {}
        int                             getId() { return id; }
        virtual Server*                 chooseServer() = 0;
        //Server*                       chooseAnyServer(){};
    };  
}