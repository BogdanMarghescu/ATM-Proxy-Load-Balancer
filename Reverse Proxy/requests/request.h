#pragma once
#include <list>
#include <string>
#include "ID_Generator.h"
#include "irequest.h"

namespace ReverseProxy
{
    typedef enum
    {
        AUTH,
        CREATE_USER,
        LOGOUT,
        INFO,
        ALG,
        TASK
    } ReqType;

    class Request : public iRequest
    {
    protected:
        int                                 identifier;
        ReqType                             type;
        std::string                         response;
        std::string                         rawCode;
        bool                                sentToServer;

    public:
        Request(ReqType type) : type(type)
        {
            identifier = -1;
            if (type != INFO) // INFO requests do not get an ID
            {
                ID_Generator &instance = ID_Generator::getInstance();
                this->identifier = instance.generateID();
            }
            sentToServer = false;
            response = "";
            rawCode = "";
        };

        virtual ~Request(){};

        virtual void                        solve() = 0;

        friend class RequestsHandler;
    };
    
}