#include "alg.h"
#include "../user.h"

using namespace ReverseProxy;

void Alg::solve()
{
    User &client = User::getInstance();
    client.setAlgorithm(this->algID);
    this->response = "ALG You selected algorithm " + std::to_string(this->algID);
}