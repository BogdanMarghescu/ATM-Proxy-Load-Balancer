#include "ip_hashing.h"
#include "../user.h"
#include <math.h>

using namespace ReverseProxy;

long long calculateDiff(char *firstIP, char *secondIP) // Calculates difference between IPs
{
    char IP1[20], IP2[20];

    strcpy(IP1, firstIP);
    strcpy(IP2, secondIP);

    unsigned char ip1[4]; // ip1 blocks
    unsigned char ip2[4]; // ip2 blocks
    long long difference = 0;

    // Parsing
    ip1[0] = atoi(strtok(IP1, "."));
    ip1[1] = atoi(strtok(NULL, "."));
    ip1[2] = atoi(strtok(NULL, "."));
    ip1[3] = atoi(strtok(NULL, "\0"));

    ip2[0] = atoi(strtok(IP2, "."));
    ip2[1] = atoi(strtok(NULL, "."));
    ip2[2] = atoi(strtok(NULL, "."));
    ip2[3] = atoi(strtok(NULL, "\0"));

    for (int i = 3; i >= 0; i--)
    {
        if (ip1[i] - ip2[i] == 0) // For optimization
            continue;
        difference = difference + (ip1[i] - ip2[i]) * pow(255, 3 - i);
    }

    return abs(difference);
}

Server *IpHashing::chooseServer()
{
    if (servers == nullptr)
        return nullptr;
    if (servers->size() == 0)
        return nullptr;

    if (nextServer == nullptr) // No server has yet been selected
    {
        for (auto it = servers->begin(); it != servers->end(); it++)
        {
            if ((it->getStatus() == true) && (it->getLoad() < 100))
            {
                BalancingAlgorithm::nextServer = &(*it);
                return &(*it);
            }
        }
        return nullptr; // No server available
    }

    User &client = User::getInstance();
    std::string clientIP = client.getIp();

    long long minDiff = calculateDiff((char *)clientIP.c_str(), (char *)servers->begin()->getIp().c_str());

    for (auto it = servers->begin(); it != servers->end(); it++)
    {
        if (it->getLoad() < 100)
            if (calculateDiff((char *)it->getIp().c_str(), (char *)clientIP.c_str()))
            {
                minDiff = calculateDiff((char *)it->getIp().c_str(), (char *)clientIP.c_str());
                return &(*it);
            }
    }

    return nullptr;
}
