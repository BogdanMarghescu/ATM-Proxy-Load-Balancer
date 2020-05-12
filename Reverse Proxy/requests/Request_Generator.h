#pragma once
#include "request.h"
namespace ReverseProxy
{
    class RequestGenerator
    {
    public:
        static Request *generate_ALG_REQUEST(int &id);
        static Request *generate_AUTH_REQUEST(std::string &user, std::string &pass);
        static Request *generate_CREATEUSER_REQUEST(std::string &user, std::string &pass);
        static Request *generate_LOGOUT_REQUEST();
        static Request *generate_INFO_REQUEST();
        static Request *generate_FACTORIAL_REQUEST(int &arg);
        static Request *generate_POWER_REQUEST(int &arg_1, int &arg_2);
        static Request *generate_ROOT_REQUEST(int &arg_1, int &arg_2);
    };  
}