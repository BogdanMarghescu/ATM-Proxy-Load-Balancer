#include <exception>
#include <string>

namespace ReverseProxy
{
    class failed_send : public std::exception
    {
        int code = 6;
    public:
        std::string what()
        {
            return "Send() failed! Exception code: " + std::to_string(code);
        }
    };
}