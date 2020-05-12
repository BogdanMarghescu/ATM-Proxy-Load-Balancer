#include "task.h"

namespace ReverseProxy
{
    class Factorial : public Task
    {
        int                             arg;

    public:
        Factorial(int &arg) : arg(arg) {}
    };   
}