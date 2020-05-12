#pragma once
#include "TcpClient.h"
#include "ServerList.h"
Q_DECLARE_METATYPE(ServerList);
Q_DECLARE_METATYPE(string);

class Client : public TcpClient
{
private:
	static Client* instance;
	ServerList serverList;
	Client() : TcpClient() { ; }
	Client(const Client&) = delete;
	~Client() { ; }
	Client(const string& ipAdress, int port) : TcpClient(ipAdress, port) { ; }

public:
	static Client& getInstance(const string& ipAdress, int port);
	static void destroyInstance();
	static Client& getInstance();
	ServerList getServerList() const { return serverList; }
	string sendCredentials(const string& credentials);	///	send credential request
	void logout();										///	send log out request
	void selectAlgorithm(int option);					///	select algorithm for reverse proxy and send a request
	void selectTask(int type, int op1, int op2 = 0);	///	send task request
	void getServersStatus();							///	send a request to get the status of the servers
	void updateServerInfo(const string& reply);			///	updates servers info based on a reply from proxy
};