#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack()
{
    std::cout << "\033[1;34m⚔️  " << this->name
              << "\033[0m attacks with their \033[1;33m" 
              << this->weapon.getType() << "\033[0m" << std::endl;
}
