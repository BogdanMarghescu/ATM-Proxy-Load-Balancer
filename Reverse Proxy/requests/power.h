#include "task.h"

namespace ReverseProxy
{
    class Power : public Task
    {
        int arg_1;
        int arg_2;

    public:
        Power(int &arg_1, int &arg_2) : arg_1(arg_1), arg_2(arg_2) {}
    };
}