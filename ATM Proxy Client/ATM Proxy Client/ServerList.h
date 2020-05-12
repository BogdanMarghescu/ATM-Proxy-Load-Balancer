#pragma once
#include "Server.h"
#include <vector>
#include <sstream>
#include <QTableWidget>

enum columns { IPAdress, Status, Load, Hits };

class ServerList
{
private:
	vector<Server> serverList;

public:
	ServerList() :serverList() { ; }
	ServerList(const string& request);				///	build server list based on a request sent by the proxy
	void updateServerList(const string& request);	///	update server list based on a request sent by the proxy
	void print(QTableWidget* table);				///	print servers information in a table
};