#include "request.h"

namespace ReverseProxy
{
    class Auth : public Request
    {
        std::string                     username;
        std::string                     password;

    public:
        Auth(std::string &user, std::string &pass) : Request(ReqType(AUTH)), username(user), password(pass){};

        void                            solve();
    };
}