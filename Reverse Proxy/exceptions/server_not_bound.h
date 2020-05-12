#include <exception>
#include <string>

namespace ReverseProxy
{
    class server_not_bound : public std::exception
    {
        int code = 1;
    public:
        std::string what()
        {
            return "Server not bound! Exception code: " + std::to_string(code);
        }
    };
}