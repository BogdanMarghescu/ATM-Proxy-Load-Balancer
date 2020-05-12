#pragma once
#include "request.h"
#include "../server.h"

namespace ReverseProxy
{
    class RequestsHandler
    {
        std::list<Request *> requests;
        std::condition_variable responseFilled;

    public:
        void addRequest(char *buffer);                  // Adds a request to the list
        void addResponse(char *buffer, Server &from);   // Adds a given response from the server
        void solveRequests();                           // Solves requests internally or sends them to the server
        void sendResponses();                           // Sends back the responses
        

        Request* dequeueResponseToSend();
        Request* dequeueRequestToSolve();
        void print();
    };
}