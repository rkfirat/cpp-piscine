#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "\033[1;32m🧟  [SPAWNED] \033[0m"
              << "\033[1;37mA nameless zombie has risen from the grave!\033[0m"
              << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}

Zombie::~Zombie(void)
{
    if (!this->name.empty())
    {
        std::cout << "\033[1;31m💀  [DESTROYED] \033[0m"
                  << "\033[1;90mZombie '\033[1;31m" << this->name << "\033[1;90m' has been laid to rest.\033[0m"
                  << std::endl;
    }
    else
    {
        std::cout << "\033[1;31m💀  [DESTROYED] \033[0m"
                  << "\033[1;90mA nameless zombie has been laid to rest.\033[0m"
                  << std::endl;
    }
}

void Zombie::announce(void)
{
    std::cout << "\033[1;36m🗣️  " 
              << (this->name.empty() ? "Nameless Zombie" : this->name)
              << "\033[0m: \033[3;37mBraiiiiiiinnnzzzZ...\033[0m"
              << std::endl;
}
