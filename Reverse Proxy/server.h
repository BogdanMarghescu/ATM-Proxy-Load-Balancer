#pragma once
#include "node.h"

namespace ReverseProxy
{
    class Server : public Node
    {
        bool up = false;
        int hits = 0;
        float load = 0.0;
        int threads = 5;
        int threads_available;

    public:
        void setStatus(bool status);
        bool getStatus();
        float getLoad();
        std::string getInfo();

        friend class RequestsHandler;
    };  
}
