#pragma once
#include <string>
#include <thread>

namespace ReverseProxy
{
    class LoggerFlag
    {
        std::string type;
    public:
        LoggerFlag(std::string type): type(type){}
        std::string getType();
    };

    class ErrorFlag : public LoggerFlag
    {
        public:
        ErrorFlag():LoggerFlag("Error flag"){};
    };
    
    class Logger
    {
        std::string path_to_log;
        std::string path_to_errorlog;
        bool write_to_errorlog;

        std::mutex mutex;

        static Logger* instance;
        Logger();
    public:
        static Logger& getInstance();
        
        Logger(Logger &other) = delete;
        void operator=(const Logger &) = delete;

        Logger& operator<<(std::string message);
        Logger& operator<<(ErrorFlag flag);

    };

}