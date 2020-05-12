#include "ID_Generator.h"
#include <time.h>

using namespace ReverseProxy;

ID_Generator *ID_Generator::instance = nullptr;

ID_Generator &ID_Generator::getInstance()
{
    if (instance == nullptr)
        instance = new ID_Generator;
    return *instance;
}

void ID_Generator::destroyInstance()
{
    if (instance != nullptr)
        delete instance;
}

void ID_Generator::addID(int id)
{
    IDs.push_back(id);
}

bool ID_Generator::exists(int id)
{
    for(auto i : IDs)
        if (i == id)
            return true;
    return false;
}

int ID_Generator::generateID()
{
    srand(time(NULL));
    int id = rand() % 2000000000;
    while(exists(id))
        id = rand() % 2000000000;
    addID(id);

    return id;
}
