#pragma once
#include "request.h"

namespace ReverseProxy
{
    class Alg : public Request
    {
        int                         algID;

    public:
        Alg(int &id) : Request(ReqType(ALG)) { algID = id; }
        void                        solve();
    };
}