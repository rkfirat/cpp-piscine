#include "Zombie.hpp"

int main(void)
{
    Zombie* zombies = zombieHorde(11, "Bob");

    delete[] zombies;
    return 0;
}
