#pragma once
#include "request.h"

namespace ReverseProxy
{
    class Info : public Request
    {
    public:
        Info() : Request(ReqType(INFO)){};
        void                            solve();
    };   
}