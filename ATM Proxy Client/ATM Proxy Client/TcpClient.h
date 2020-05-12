#pragma once
#include "ITcpClient.h"
#include "Log.h"
#include "ConnectException.h"
#include "UserException.h"
#include "TaskGenerator.h"
#include <WS2tcpip.h>
#include <string>
#include <QDebug>
#pragma comment (lib, "ws2_32.lib")

class TcpClient : public ITcpClient
{
public:
	TcpClient() : m_ipAdress("127.0.0.1"), m_port(54000), m_socket() { ; }
	TcpClient(const string& ipAdress, int port) : m_ipAdress(ipAdress), m_port(port), m_socket() { ; }
	int startClient();
	int connectProxy();
	string getResponseFromServer();
	void sendToServer(int serverSocket, const string& msg);
	void closeClientConnections();

protected:
	string	m_ipAdress; //IP-ul clientului
	int		m_port;		//Port-ul clientului
	int		m_socket;	//Socket-ul pe care asculta
};