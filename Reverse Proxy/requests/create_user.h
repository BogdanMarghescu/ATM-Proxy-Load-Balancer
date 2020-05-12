#include "request.h"

namespace ReverseProxy
{
    class CreateUser : public Request
    {
        std::string                     username;
        std::string                     password;

    public:
        CreateUser(std::string &user, std::string &pass) : Request(ReqType(CREATE_USER)), username(user), password(pass){};

        void                            solve();
    }; 
}