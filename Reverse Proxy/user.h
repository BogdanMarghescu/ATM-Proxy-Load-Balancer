#pragma once
#include "node.h"

namespace ReverseProxy
{
class User : public Node
{
    bool loggedIn;
    int algorithm;

    static User *instance;
    User();

public:
    static User &getInstance();
    static void destroyInstance();
    User(User &other) = delete;
    void operator=(const User &) = delete;

    bool authenticate(std::string &username, std::string &password);
    void deauthenticate();
    bool createNewUser(std::string &username, std::string &password);

    bool isLoggedIn();
    void setAlgorithm(int &alg);
    int getAlgorithm();

};
} // namespace ReverseProxy
