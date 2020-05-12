#pragma once
#include "ITcpListener.h"
#include <iostream>
#include <WS2tcpip.h>
#include <string>
#include "Log.h"
#include <vector>
#include <sstream>
#include <iterator>
#include <mutex>
#include <map>
#include <list>
#include <Windows.h>
#include "Base64.h"

#define POOL_SIZE 5

#pragma comment (lib, "ws2_32.lib")
class TcpListener :
	public ITcpListener
{
public:
	TcpListener(std::string ipAdress, int port) :
		m_ipAdress(ipAdress), m_port(port) {};

	int init();

	int run();

protected:
	//std::vector<std::thread>				pool;
	static std::list<std::string>			resultList;

	virtual void onClientDisconnected(int clientSocket) = 0;

	virtual void onMessageReceived(int clientSocket, std::string msg) = 0;

	void sendToClient(int clientSocket, std::string msg);

private:
	std::string		m_ipAdress;			//IP-ul serverului
	int				m_port;				//Port-ul serverului
	int				m_socket;			//Socket-ul pe care asculta
	int				m_clientSocket;		//Socket-ul pe care se conecteaza clientul
};

