#include <string>
#include <sstream>
#include <iostream>

#include "../gui/Widget.h"

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
        Logger(Gui::LogWindow*);
        LoggerStream Log(LogLevel);
        void Log(LogLevel, const std::string&);
    private:
        Gui::LogWindow* window;
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