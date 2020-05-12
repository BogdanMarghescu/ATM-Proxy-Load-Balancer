#define _CRT_SECURE_NO_WARNINGS
#include "Log.h"
Log* Log::instance = nullptr;

Log& Log::getInstance()
{
	if (!instance)
	{
		Log::instance = new Log();
	}
	return *Log::instance;
}

void Log::destroyInstance()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

void Log::LogInfo(std::string msg)
{
	std::ofstream fout("log.txt", std::ios::app);
	auto end = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	fout << msg << "\t\t\t\t\t\t" << std::ctime(&end_time);
	fout.close();
}
