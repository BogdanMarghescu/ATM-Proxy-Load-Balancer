#include <exception>
#include <string>

namespace ReverseProxy
{
    class server_not_listening : public std::exception
    {
        int code = 2;
    public:
        std::string what()
        {
            return "Server not listening! Exception code: " + std::to_string(code);
        }
    };
}