#include "Zombie.hpp"
#include <iostream>

int main() {
    int N = 5;
    std::cout << "Creating a horde of " << N << " zombies..." << std::endl;

    Zombie* horde = zombieHorde(N, "HordeZombie");

    if (horde) {
        for (int i = 0; i < N; i++) {
            std::cout << "Zombie " << i + 1 << ": ";
            horde[i].announce();
        }

        delete[] horde;  // Properly delete the array of zombies
    }

    return 0;
}
