#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

    typedef void (Harl::*ComplaintFunction)(void);
    static const int NUM_LEVELS = 4;
    ComplaintFunction functions[NUM_LEVELS];
    std::string levels[NUM_LEVELS];

public:
    Harl();
    void complain(std::string level);
    void filterComplain(std::string level);

    // Enum for log levels
    enum LogLevel {
        NONE = -1,
        DEBUG,
        INFO,
        WARNING,
        ERROR
    };

    LogLevel getLevel(std::string level);
};

#endif
