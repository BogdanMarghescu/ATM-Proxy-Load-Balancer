#include "logout.h"
#include "../user.h"

using namespace ReverseProxy;

void Logout::solve()
{
    User &client = User::getInstance();
    client.deauthenticate();
    //response = "LOGOUT";
}