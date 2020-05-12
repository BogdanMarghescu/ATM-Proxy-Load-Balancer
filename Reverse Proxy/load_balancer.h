#include "requests/requests_handler.h"
#include "algorithms/Algortihm_Generator.h"
#include "user.h"
#include "server.h"
#include "Logger.h"
#include <list>
#include <vector>
#include <thread>

namespace ReverseProxy
{
    class LoadBalancer
    {
        int                                 my_socket;
        RequestsHandler                     req_handler;
        User&                               client = User::getInstance();  
        std::list<Server>                   servers;                        // List of servers used
        fd_set                              ready_sockets, current_sockets; // Used for select()
        std::vector<BalancingAlgorithm *>   algorithms;                     // Used algorithms

        Logger&                             logger = Logger::getInstance();
        
        std::mutex mutex;
        std::mutex server_mutex;
        std::condition_variable             cond_var;

        void                                inputServers();             // Gets server IPs from txt file
        void                                checkServersAvailability(); // At startup; verifies if servers are up
        void                                requestServersInfo();       // Constantly gets INFO from Servers
        void                                waitForRequests();
        void                                waitForResponses();

        static LoadBalancer*                instance;
        LoadBalancer();
        ~LoadBalancer();

    public:
        static LoadBalancer&                getInstance();
        LoadBalancer(const LoadBalancer &) = delete;
        void                                operator=(const LoadBalancer &) = delete;
        static void                         destroyInstance();

        void                                waitNewUser();
        void                                start();
        std::string                         getServersInfo();

        friend class RequestsHandler;
    };
    
}

