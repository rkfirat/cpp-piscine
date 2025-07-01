#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

HumanB::~HumanB() {}

void HumanB::attack()
{
    if (this->weapon)
    {
        std::cout << "\033[1;36m🛡️  " << this->name
                  << "\033[0m attacks with their \033[1;33m"
                  << this->weapon->getType() << "\033[0m" << std::endl;
    }
    else
    {
        std::cout << "\033[1;31m❌ " << this->name
                  << " has no weapon\033[0m" << std::endl;
    }
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}
