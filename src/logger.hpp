#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include "templateClasses.cpp"

class Logger : public Singleton<Logger>
{
public:
    enum LogLevel
    {
        ERROR,
        WARN,
        INFO,
        DEBUG,
        DEBUG1,
        DEBUG2
    };
    static void logLevel(const LogLevel &log_level);
    static Logger::LogLevel logLevel();
    static void log(const LogLevel &log_level, const std::string &msg);
    static void logError(const std::string &msg);
    static void logWarn(const std::string &msg);
    static void logInfo(const std::string &msg);

protected:
    friend Singleton;
    LogLevel log_level_;
    Logger() : log_level_(LogLevel::INFO){};
};

#endif // LOGGER_HPP
