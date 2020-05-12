#include <exception>
#include <string>

namespace ReverseProxy
{
    class failed_select : public std::exception
    {
        int code = 4;
    public:
        std::string what()
        {
            return "Error receiving traffic from servers! Exception code: " + std::to_string(code);
        }
    };
}