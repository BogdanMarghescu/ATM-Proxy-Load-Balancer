#include <exception>
#include <string>

namespace ReverseProxy
{
    class timeout_select : public std::exception
    {
        int code = 6;
    public:
        std::string what()
        {
            return "Select() has timed out! Exception code: " + std::to_string(code);
        }
    };
}