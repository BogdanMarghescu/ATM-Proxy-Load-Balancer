#pragma once
#include "request.h"

namespace ReverseProxy
{
    class Task : public Request
    {
    public:
        Task() : Request(ReqType(TASK)) {}
        void                            solve(){}; // RequestHandler solves tasks
    };
}