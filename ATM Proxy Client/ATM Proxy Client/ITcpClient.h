#pragma once
#include <sstream>
#include <QMessageBox>
#include "Base64.h"
using namespace std;

class ITcpClient
{
protected:
	virtual void sendToServer(int serverSocket, const string& msg) = 0;
	virtual string getResponseFromServer() = 0;
public:
	virtual int startClient() = 0;
	virtual int connectProxy() = 0;
};