#define _CRT_SECURE_NO_WARNINGS
#include"Log.h"

Log* Log::instance = nullptr;

Log& Log::getInstance()
{
	if (!Log::instance)
		Log::instance = new Log;
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

string get_current_time()
{
	auto end = std::chrono::system_clock::now();
	time_t end_time = std::chrono::system_clock::to_time_t(end);
	string time_string = (string)(std::ctime(&end_time));
	time_string.pop_back();
	return time_string + ":\t";
}

void Log::open(const string& filename)
{
	log.open(filename, ios::out);
}

void Log::write(const string& message)
{
	log << get_current_time() << message << endl;
}

void Log::close()
{
	log.clear();
	log.close();
}