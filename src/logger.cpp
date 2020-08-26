#include "logger.hpp"
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <iostream>

void Logger::logLevel(const LogLevel &log_level)
{
    auto &logger = instance();
    logger.log_level_ = log_level;
}
Logger::LogLevel Logger::logLevel()
{
    auto &logger = instance();
    return logger.log_level_;
}
void Logger::log(const LogLevel &log_level, const std::string &msg)
{
    auto &logger = instance();
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);
    std::stringstream time_ss;
    time_ss << std::put_time(&tm, "%a %b %d %H:%M:%S %Y");

    if (log_level <= logger.logLevel())
    {
        std::cout << time_ss.str() << " LogLevel::" << log_level << ": " << msg << std::endl;
    }
}

void Logger::logError(const std::string &msg)
{
    Logger::log(LogLevel::ERROR, msg);
}
void Logger::logWarn(const std::string &msg)
{
    Logger::log(LogLevel::WARN, msg);
}
void Logger::logInfo(const std::string &msg)
{
    Logger::log(LogLevel::INFO, msg);
}
