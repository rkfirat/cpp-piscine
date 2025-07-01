#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
    std::cout << "\033[1;32m🧟  [SPAWNED] \033[0m"
              << "\033[1;37mZombie '\033[1;35m" << this->name << "\033[1;37m' has risen from the grave!\033[0m"
              << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << "\033[1;31m💀  [DESTROYED] \033[0m"
              << "\033[1;90mZombie '\033[1;31m" << this->name << "\033[1;90m' has been laid to rest.\033[0m"
              << std::endl;
}

void Zombie::announce(void)
{
    std::cout << "\033[1;36m🗣️  " << this->name 
              << "\033[0m: \033[3;37mBraiiiiiiinnnzzzZ...\033[0m"
              << std::endl;
}
