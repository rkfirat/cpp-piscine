#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("robot")
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "\033[32m🤖 [FragTrap] Unit deployed: " << name << " (default configuration)\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "\033[36m🔧 [FragTrap] Custom unit initialized: " << name << "\033[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "\033[34m📋 [FragTrap] Clone unit created from: " << other.name << "\033[0m" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other) {
        ClapTrap::operator=(other);
        hitPoints = 100;
        energyPoints = 100;
        attackDamage = 30;
    }
    std::cout << "\033[35m📝 [FragTrap] Configuration copied to: " << this->name << "\033[0m" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "\033[31m💀 [FragTrap] Unit " << name << " has been decommissioned.\033[0m" << std::endl;
}

void FragTrap::attack(const std::string &target) {
    if (energyPoints > 0 && hitPoints > 0) {
        std::cout << "\033[33m⚔️  [FragTrap] " << name << " launches an attack on " << target
                  << ", dealing " << attackDamage << " damage! (EP--)\033[0m" << std::endl;
        energyPoints--;
    } else {
        std::cout << "\033[31m❌ [FragTrap] " << name << " attempted to attack but failed (out of energy or destroyed).\033[0m" << std::endl;
    }
}

void FragTrap::takeDamage(unsigned int amount) {
    hitPoints -= amount;
    if ((int)hitPoints < 0)
        hitPoints = 0;
    std::cout << "\033[91m💢 [FragTrap] " << name << " sustained " << amount
              << " damage! [HP: " << hitPoints << "]\033[0m" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
    if (energyPoints > 0 && hitPoints > 0) {
        hitPoints += amount;
        energyPoints--;
        std::cout << "\033[92m🛠️  [FragTrap] " << name << " initiated self-repair: +" << amount
                  << " HP! [HP: " << hitPoints << ", EP: " << energyPoints << "]\033[0m" << std::endl;
    } else {
        std::cout << "\033[31m❌ [FragTrap] " << name << " failed to repair (insufficient energy or offline).\033[0m" << std::endl;
    }
}

void FragTrap::highFiveGuys(void)
{
    std::cout << "\033[93m🖐️  [FragTrap] " << name << " requests a positive high-five! ✋\033[0m" << std::endl;
}
