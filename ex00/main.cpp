#include "Zombie.hpp"
#include <iostream>

int main() {
    // Stack allocation example
    std::cout << "Creating zombie on stack:" << std::endl;
    randomChump("Stack Zombie");

    // Heap allocation example
    std::cout << "\nCreating zombie on heap:" << std::endl;
    Zombie* heapZombie = newZombie("Heap Zombie");
    heapZombie->announce();
    delete heapZombie;  // Don't forget to free heap memory

    return 0;
}
