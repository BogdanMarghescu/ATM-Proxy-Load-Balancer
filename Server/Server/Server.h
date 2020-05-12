#pragma once
#include "TcpListener.h"
#include "ITask.h"

class Server :
	public TcpListener
{
public:
	static Server& getInstance(std::string ipAdress, int port);
	static void destroyInstance();

	
private:
	static Server* instance;

	Server(std::string ipAdress, int port) :
		TcpListener(ipAdress, port), hits(0) {};
	Server(const Server&) = delete;
	~Server() {};


	std::vector<std::thread>		pool;
	unsigned int					hits;     //number of tasks made by the server
	
	void onClientDisconnected(int clientSocket) override;

	void onMessageReceived(int clientSocket, std::string msg) override;

	friend void handleTask(ITask* task, std::string taskID);

};

