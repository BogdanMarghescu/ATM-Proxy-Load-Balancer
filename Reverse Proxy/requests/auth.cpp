#include "auth.h"
#include "../user.h"

using namespace ReverseProxy;

void Auth::solve()
{
    User &client = User::getInstance();
    if (client.isLoggedIn())
    {
        response = "AUTH 1";
        return;
    }
    if (client.authenticate(username, password) == true)
    {
        response = "AUTH 0";
        return;
    }
    else
    {
        response = "AUTH 1";
        return;
    }
}