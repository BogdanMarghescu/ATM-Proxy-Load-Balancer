#pragma once
#include "request.h"

namespace ReverseProxy
{
    class Logout : public Request
    {
    public:
        Logout() : Request(ReqType(LOGOUT)){};
        void                            solve();
    };  
}