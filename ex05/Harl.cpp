#include "Harl.hpp"
#include <iostream>

Harl::Harl() {
    functions[0] = &Harl::debug;
    functions[1] = &Harl::info;
    functions[2] = &Harl::warning;
    functions[3] = &Harl::error;

    levels[0] = "DEBUG";
    levels[1] = "INFO";
    levels[2] = "WARNING";
    levels[3] = "ERROR";
}

void Harl::debug(void) {
    std::cout << "[ DEBUG ]\nI love having extra bacon for my "
              << "7XL-double-cheese-triple-pickle-special-ketchup burger. "
              << "I really do!\n" << std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. "
              << "You didn't put enough bacon in my burger! If you did, "
              << "I wouldn't be asking for more!\n" << std::endl;
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. "
              << "I've been coming for years whereas you started working here since last month.\n"
              << std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n"
              << std::endl;
}

void Harl::complain(std::string level) {
    for (int i = 0; i < NUM_LEVELS; i++) {
        if (levels[i] == level) {
            (this->*functions[i])();
            return;
        }
    }
    std::cout << "[ Probably complaining about insignificant problems ]\n" << std::endl;
}
