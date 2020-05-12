#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include <string>
using namespace std;

class Log
{
public:
	static Log& getInstance();
	static void destroyInstance();
	void open(const string& filename);
	void write(const string& message);
	void close();

private:
	static Log* instance;
	ofstream log;
	Log() { ; }
	Log(const Log&) = delete;
	~Log() { ; }
};