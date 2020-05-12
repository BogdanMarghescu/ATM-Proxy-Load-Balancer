#include "Logger.h"
#include <sys/stat.h>
#include <fstream>
#include <time.h>

using namespace ReverseProxy;

Logger *Logger::instance = nullptr;

Logger::Logger()
{
    path_to_log = "logs/log.txt";
    path_to_errorlog = "logs/errorlog.txt";
    write_to_errorlog = false;

    // Create log files if they do not exist
    struct stat buffer;
    if (stat(path_to_log.c_str(), &buffer) != 0)
    {
        std::ofstream out(path_to_log, std::ios::out);
        out.close();
    }
    if (stat(path_to_errorlog.c_str(), &buffer) != 0)
    {
        std::ofstream out(path_to_errorlog, std::ios::out);
        out.close();
    }
}

Logger &Logger::getInstance()
{
    if (instance == nullptr)
        instance = new Logger;
    return *instance;
}

Logger &Logger::operator<<(std::string message)
{
    std::ofstream out;
    time_t t = time(NULL);
    struct tm *systime = std::localtime(&t);

    mutex.lock();
    if (write_to_errorlog == true)
    {
        out.open(path_to_errorlog, std::ios::app);
    }
    else
    {
        out.open(path_to_log, std::ios::app);
    }

    out << "[" << systime->tm_mday << "." << systime->tm_mon + 1 << "." << systime->tm_year + 1900 << " ";
    out << systime->tm_hour << ":" << systime->tm_min << ":" << systime->tm_sec << "] ";
    out << message << std::endl;

    out.close();
    mutex.unlock();
    write_to_errorlog = false; // Reset the flag

    return *this;
}

Logger &Logger::operator<<(ErrorFlag flag)
{
    if (flag.getType() == "Error flag")
        write_to_errorlog = true;

    return *this;
}

std::string LoggerFlag::getType()
{
    return type;
}