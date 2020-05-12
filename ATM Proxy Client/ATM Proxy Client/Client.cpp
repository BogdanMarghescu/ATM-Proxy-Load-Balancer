#include "Client.h"

Client* Client::instance = nullptr;

Client& Client::getInstance(const string& ipAdress, int port)
{
	if (!Client::instance)
		Client::instance = new Client(ipAdress, port);
	return *Client::instance;
}

Client& Client::getInstance()
{
	if (!Client::instance)
		Client::instance = new Client;
	return *Client::instance;
}

void Client::destroyInstance()
{
	if (instance)
	{
		User::destroyInstance();
		delete instance;
		instance = nullptr;
	}
}

string Client::sendCredentials(const string& credentialRequest)
{
	sendToServer(m_socket, credentialRequest);
	string credentialResponse = getResponseFromServer();
	Log::getInstance().write("SERVER> " + credentialResponse + "\n");
	return credentialResponse;
}

void Client::logout()
{
	string logoutRequest = "LOGOUT";
	sendToServer(m_socket, logoutRequest);
	User::destroyInstance();
	Log::getInstance().write("Logging out...\n");
	closeClientConnections();
}

void Client::getServersStatus()
{
	sendToServer(m_socket, "INFO");
}

void Client::selectAlgorithm(int option)
{
	string algRequest = "ALG ";
	if ((option != 1) && (option != 2) && (option != 3))
		option = 1;
	algRequest += to_string(option);
	sendToServer(m_socket, algRequest);
}

void Client::selectTask(int type, int op1, int op2)
{
	ITask* task = TaskGenerator::generate(type, op1, op2);
	string taskRequest = ((Task*)task)->getInfo();
	sendToServer(m_socket, taskRequest);
}

void Client::updateServerInfo(const string& reply)
{
	serverList.updateServerList(reply);
}