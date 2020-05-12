#pragma once
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>

class Log
{
public:
	static Log& getInstance();
	static void destroyInstance();

	static void LogInfo(std::string msg);

private:
	static Log* instance;

	Log() {};
	Log(const Log&) = delete;
	~Log() {};
};

