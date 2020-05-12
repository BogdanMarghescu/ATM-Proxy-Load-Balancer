#pragma once

namespace ReverseProxy
{
    class iRequest
    {
    public:
        virtual void                    solve() = 0;
    }; 
}