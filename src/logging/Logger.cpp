#include "Logger.h"

using namespace Logging;

Logger::Logger() {}

void Logger::Log(LogLevel level, const std::string& message)
{
    std::stringstream stream;
    switch(level)
    {
        case INFO:
            stream << "[INFO]: " << message << std::endl;
            entries.push(stream.str());
            break;
    }
}

LoggerStream Logger::Log(LogLevel level)
{
    return LoggerStream(*this, level);
}

std::queue<std::string>* Logger::GetQueue()
{
    return &entries;
}

LoggerStream::LoggerStream(Logger& logger, LogLevel level)
    : logger(logger)
    , level(level) {}

LoggerStream::~LoggerStream()
{
    const std::string message = stream.str();
    // in case the compiler does not omit copying LoggerStream
    if (!message.empty())
    {
        logger.Log(level, message);
    }
};
