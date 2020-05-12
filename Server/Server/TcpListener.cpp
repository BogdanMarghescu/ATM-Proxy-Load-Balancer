#include "TcpListener.h"
std::list<std::string> TcpListener::resultList;

int TcpListener::init()
{
	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);

	int wsOk = WSAStartup(ver, &wsData);
	if (wsOk != 0)
	{
		Log::getInstance().LogInfo("[ERROR]:Can't Initialize winsock!");
		std::cout << "Can't Initialize winsock! Quitting" << std::endl;
		return WSAGetLastError();
	}

	m_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (m_socket == INVALID_SOCKET)
	{
		Log::getInstance().LogInfo("[ERROR]:Can't create a socket!");
		std::cout << "Can't create a socket! Quitting" << std::endl;
		return WSAGetLastError();
	}

	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000);
	hint.sin_addr.s_addr = INADDR_ANY;
	//inet_pton(AF_INET, m_ipAdress.c_str(), &hint.sin_addr);

	if (bind(m_socket, (sockaddr*)&hint, sizeof(hint)) == -1) {
		Log::getInstance().LogInfo("[ERROR]:Failed to bind!");
		std::cout << "[ERROR]:Failed to bind!" << std::endl;
		return WSAGetLastError();
	}

	listen(m_socket, SOMAXCONN);
	
	m_clientSocket = 0;

	return 0;
}

int TcpListener::run()
{
	while (true)
	{
		sockaddr_in client;
		int clientSize = sizeof(client);

		while (m_clientSocket <= 0 || m_clientSocket > 1000) {
			m_clientSocket = accept(m_socket, (sockaddr*)&client, &clientSize);
		}

		char host[NI_MAXHOST];		
		char service[NI_MAXSERV];	

		ZeroMemory(host, NI_MAXHOST); 
		ZeroMemory(service, NI_MAXSERV);

		if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
		{	
			Log::getInstance().LogInfo("[INFO]:" + std::string(host) + " connected on port " + std::string(service));
			std::cout << host << " connected on port " << service << std::endl;
		}
		else
		{
			inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);

			Log::getInstance().LogInfo("[INFO]:" + std::string(host) +
				" connected on port " + (char*)(client.sin_port));

			std::cout << host << " connected on port " <<
				ntohs(client.sin_port) << std::endl;
		}

		char buf[1024];

		
		while (true)
		{
			back:ZeroMemory(buf, 1024);

			while (!resultList.empty())
			{
				std::cout << "[RESULT]:" << resultList.front();
				sendToClient(m_clientSocket, resultList.front());
				resultList.pop_front();
			}

			int bytesReceived = recv(m_clientSocket, buf, 1024, 0);
			if (bytesReceived == SOCKET_ERROR)
			{
				Log::getInstance().LogInfo("[ERROR]:Error in recv()");
				std::cout << "Error in recv(). Quitting" << std::endl;

				goto back;
			}

			if (bytesReceived == 0)
			{
				onClientDisconnected(m_clientSocket);
				closesocket(m_clientSocket);
				m_clientSocket = 0;
				break;
			}
			if (bytesReceived > 2)
			{
				onMessageReceived(m_clientSocket, buf);
			}

		}
	}
	closesocket(m_clientSocket);
	closesocket(m_socket);

	WSACleanup();

	system("pause");
	return 0;
}

void TcpListener::sendToClient(int clientSocket, std::string msg)
{
	std::string buff = Base64::getInstance().encode(msg);
	
	int test = send(clientSocket, buff.c_str(), buff.length(), 0);
	if (test == SOCKET_ERROR)
	{
		Log::getInstance().LogInfo("[ERROR]:Error sending a message!");
		std::cout << "Eroare la trimiterea mesajului" + msg << std::endl;
	}
	else {
		Log::getInstance().LogInfo("Message sent to #" + std::to_string(clientSocket));
	}
}
