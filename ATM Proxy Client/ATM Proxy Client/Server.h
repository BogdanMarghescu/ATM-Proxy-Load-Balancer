#pragma once
#include<iostream>
using namespace std;

class Server
{
private:
	string ipAdress;
	bool status;
	float load;
	int hits;

public:
	Server(const string& ip, bool stat, float ld, int hit) :ipAdress(ip), status(stat), load(ld), hits(hit) { ; }
	string getIPAdress() const { return ipAdress; }
	bool getStatus() const { return status; }
	float getLoad() const { return load; }
	int getHits() const { return hits; }
};