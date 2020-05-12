#include "user.h"
#include <fstream>
#include <sys/stat.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace ReverseProxy;

User *User::instance = nullptr;

User &User::getInstance()
{
    if (instance == nullptr)
        instance = new User;
    return *instance;
}

User::User()
{
    loggedIn = false;
    algorithm = 1;
}

bool User::authenticate(std::string &username, std::string &password)
{
    std::string pass;
    std::ifstream in;

    in.open("users/" + username + ".txt", std::ios::in);
    if (in.is_open() == false)
        return false;

    std::getline(in, pass);

    if (pass == password)
    {
        loggedIn = true;
        return true;
    }
    return false;
}

bool User::createNewUser(std::string &username, std::string &password)
{
    struct stat buffer;
    if (stat(("users/" + username + ".txt").c_str(), &buffer) == 0) // Existing user
        return false;

    std::ofstream out;
    out.open("users/" + username + ".txt", std::ios::out);
    out << password;
    out.close();

    loggedIn = true;
    return true;
}

bool User::isLoggedIn()
{
    if (loggedIn)
        return true;
    return false;
}

void User::setAlgorithm(int &alg)
{
    algorithm = alg;
}

int User::getAlgorithm()
{
    return algorithm;
}

void User::deauthenticate()
{
    loggedIn = false;
    algorithm = 1;

    close(this->socket);
}