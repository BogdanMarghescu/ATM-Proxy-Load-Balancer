#pragma once
#include <iostream>
#include "ITask.h"
#include <thread>

class ITcpListener
{
protected:
	virtual void onClientDisconnected(int clientSocket) = 0;
	virtual void onMessageReceived(int clientSocket, std::string msg) = 0;
	virtual void sendToClient(int clientSocket, std::string msg) = 0;
public:
	virtual int init() = 0;
	virtual int run() = 0;
};

