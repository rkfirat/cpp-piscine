#include "Zombie.hpp"

int main(void)
{
    {
        Zombie zombie("Foo");
        zombie.announce();
    }
    std::cout << std::endl;
    std::cout << std::endl;
    {
        randomChump("Foo");
    }
    std::cout << std::endl;
    std::cout << std::endl;
    {
        Zombie* newZoombie = newZombie("Foo");
        newZoombie->announce();
        delete newZoombie;
    }
    return 0;
}
