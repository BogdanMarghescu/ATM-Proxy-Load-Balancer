#include <exception>
#include <string>

namespace ReverseProxy
{
    class failed_recv : public std::exception
    {
        int code = 7;
    public:
        std::string what()
        {
            return "Recv() failed! Exception code: " + std::to_string(code);
        }
    };
}