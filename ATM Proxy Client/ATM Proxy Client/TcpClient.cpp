#include "TcpClient.h"

void TcpClient::sendToServer(int serverSocket, const string& msg)
{
	try
	{
		Log::getInstance().write("CLIENT> " + msg + "\n");
		string encrypt_msg = Base64::encode(msg);
		int sendresult = send(serverSocket, encrypt_msg.c_str(), encrypt_msg.size() + 1, 0);
		if (sendresult == SOCKET_ERROR)
		{
			int lastError = WSAGetLastError();
			closesocket(m_socket);
			throw new ConnectException(lastError, "Proxy disconnected!\n");
		}
	}
	catch (ConnectException* e)
	{
		Log::getInstance().write("CONNECTION ERROR #" + to_string(e->getCode()) + ": " + e->getMessage() + "\n");
		QMessageBox::critical(nullptr, "Connection Error", e->getError().c_str());
		delete e;
		exit(-1);
	}
}

string TcpClient::getResponseFromServer()
{
	char buf[4096];
	ZeroMemory(buf, 4096);
	int bytesReceived = recv(m_socket, buf, 4096, 0);
	if (bytesReceived == SOCKET_ERROR)
	{
		int lastError = WSAGetLastError();
		throw new ConnectException(lastError, "Proxy disconnected!\n");
	}
	else if (bytesReceived == 0)
		throw new ConnectException(-2, "Proxy disconnected!\n");		
	else
	{
		string reply = string(buf, 0, bytesReceived);
		string decrypt_reply = Base64::decode(reply);
		return decrypt_reply;
	}
}

int TcpClient::startClient()
{
	try
	{
		// Initialize WinSock
		WSAData data;
		WORD ver = MAKEWORD(2, 2);
		int wsResult = WSAStartup(ver, &data);
		if (wsResult != 0)
		{
			throw new ConnectException(wsResult, "Can't start Winsock!\n");
		}

		// Create socket
		m_socket = socket(AF_INET, SOCK_STREAM, 0);
		if (m_socket == INVALID_SOCKET)
		{
			int lastError = WSAGetLastError();
			WSACleanup();
			throw new ConnectException(lastError, "Can't create socket!\n");
		}
		return 0;
	}
	catch (ConnectException* e)
	{
		Log::getInstance().write("CONNECTION ERROR #" + to_string(e->getCode()) + ": " + e->getMessage() + "\n");
		QMessageBox::critical(nullptr, "Connection Error", e->getError().c_str());
		delete e;
	}
	return 1;
}

int TcpClient::connectProxy()
{
	try
	{
		// Fill in a hint structure
		sockaddr_in hint;
		hint.sin_family = AF_INET;
		hint.sin_port = htons(m_port);
		inet_pton(AF_INET, m_ipAdress.c_str(), &hint.sin_addr);

		// Connect to server
		int connResult = ::connect(m_socket, (sockaddr*)&hint, sizeof(hint));
		if (connResult == SOCKET_ERROR)
		{
			int lastError = WSAGetLastError();
			closesocket(m_socket);
			WSACleanup();
			throw new ConnectException(lastError, "Can't connect to server!\n");
			return -1;
		}
		return 0;
	}
	catch (ConnectException* e)
	{
		Log::getInstance().write("CONNECTION ERROR #" + to_string(e->getCode()) + ": " + e->getMessage() + "\n");
		QMessageBox::critical(nullptr, "Connection Error", e->getError().c_str());
		delete e;
		return -1;
	}
}

void TcpClient::closeClientConnections()
{
	closesocket(m_socket);
	WSACleanup();
}