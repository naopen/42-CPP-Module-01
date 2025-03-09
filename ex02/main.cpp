#include <iostream>
#include <string>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    // Print memory addresses
    std::cout << "Memory addresses:" << std::endl;
    std::cout << "str        : " << &str << std::endl;
    std::cout << "stringPTR  : " << stringPTR << std::endl;
    std::cout << "stringREF  : " << &stringREF << std::endl;

    // Print values
    std::cout << "\nValues:" << std::endl;
    std::cout << "str        : " << str << std::endl;
    std::cout << "stringPTR  : " << *stringPTR << std::endl;
    std::cout << "stringREF  : " << stringREF << std::endl;

    return 0;
}
