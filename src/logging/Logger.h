#include <string>
#include <sstream>
#include <iostream>
#include <queue>

namespace Logging
{
    enum LogLevel
    {
        DEBUG,
        INFO,
        WARN,
        ERROR
    };

    // forward declaration for use in Logger.
    class LoggerStream;

    /// @brief from https://nuah.livejournal.com/322022.html
    class Logger
    {
    public:
        Logger();
        LoggerStream Log(LogLevel);
        void Log(LogLevel, const std::string&);
        std::queue<std::string>* GetQueue();
    private:
        std::queue<std::string> entries;
    };

    /// @brief from https://nuah.livejournal.com/322022.html
    class LoggerStream
    {
    public:
        ~LoggerStream();

        template<typename T>
        LoggerStream& operator<<(const T& value){
            stream << value;
            return (*this);
        }
    private:
        friend Logger;
        LoggerStream(Logger&, LogLevel);
        Logger& logger;
        LogLevel level;
        std::stringstream stream;
    };
};