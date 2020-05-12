#pragma once
#include <list>

namespace ReverseProxy
{
    class ID_Generator
    {
        std::list<int> IDs;

        static ID_Generator* instance;

        ID_Generator(){}
        ~ID_Generator(){}
    public:
        static ID_Generator& getInstance();
        void destroyInstance();

        void addID(int id);
        int generateID();
        bool exists(int id);
    };
}