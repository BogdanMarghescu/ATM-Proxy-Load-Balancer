#include <exception>
#include <string>

namespace ReverseProxy
{
    class server_not_accepting : public std::exception
    {
        int code = 3;
    public:
        std::string what()
        {
            return "Server not accepting connections! Exception code: " + std::to_string(code);
        }
    };
}