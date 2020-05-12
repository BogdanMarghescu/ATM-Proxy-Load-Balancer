#include "Request_Generator.h"
#include "request.h"
#include "alg.h"
#include "auth.h"
#include "create_user.h"
#include "logout.h"
#include "info.h"
#include "root.h"
#include "power.h"
#include "factorial.h"

using namespace ReverseProxy;

Request *RequestGenerator::generate_ALG_REQUEST(int &id)
{
    return new Alg(id);
}
Request *RequestGenerator::generate_AUTH_REQUEST(std::string &user, std::string &pass)
{
    return new Auth(user, pass);
}

Request *RequestGenerator::generate_CREATEUSER_REQUEST(std::string &user, std::string &pass)
{
    return new CreateUser(user, pass);
}

Request *RequestGenerator::generate_LOGOUT_REQUEST()
{
    return new Logout();
}

Request *RequestGenerator::generate_INFO_REQUEST()
{
    return new Info();
}

Request *RequestGenerator::generate_FACTORIAL_REQUEST(int &arg)
{
    return new Factorial(arg);
}

Request *RequestGenerator::generate_POWER_REQUEST(int &arg_1, int &arg_2)
{
    return new Power(arg_1, arg_2);
}

Request *RequestGenerator::generate_ROOT_REQUEST(int &arg_1, int &arg_2)
{
    return new Root(arg_1, arg_2);
}
