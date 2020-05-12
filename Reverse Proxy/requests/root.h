#include "task.h"

namespace ReverseProxy
{
    class Root : public Task
    {
        int                             arg_1;
        int                             arg_2;

    public:
        Root(int &arg_1, int &arg_2) : arg_1(arg_1), arg_2(arg_2) {}
        void                            solve(){}
    };
}