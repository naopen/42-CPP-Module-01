#include "Harl.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <log level>" << std::endl;
        std::cerr << "Log levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
        return 1;
    }

    Harl harl;
    harl.filterComplain(argv[1]);

    return 0;
}
