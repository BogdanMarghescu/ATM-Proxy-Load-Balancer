#include "create_user.h"
#include "../user.h"

using namespace ReverseProxy;

void CreateUser::solve()
{
    User &client = User::getInstance();
    if(client.isLoggedIn())
        {
            response = "CREATE_USER 1";
            return;
        }
    if (client.createNewUser(username, password) == true)
        {
            response = "CREATE_USER 0";
            return;
        }
    else
    {
        response = "CREATE_USER 1";
        return;
    }
}