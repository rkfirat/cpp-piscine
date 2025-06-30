#include "Zombie.hpp"


Zombie::Zombie()
{
    std::cout << "Zombie is created!" << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}


Zombie::~Zombie(void)
{
    if (!this->name.empty())
        std::cout << this->name << " is destroyed!" << std::endl;
    else
        std::cout << "Zombie is destroyed!" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}