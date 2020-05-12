#pragma once
#include "../server.h"

namespace ReverseProxy
{
    class iBalancingAlgorithm
    {
    public:
        virtual Server*                 chooseServer() = 0;
    };  
}