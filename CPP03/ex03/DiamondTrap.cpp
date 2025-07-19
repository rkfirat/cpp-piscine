#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("robot_clap_name"), FragTrap(), ScavTrap(), name("robot")
{
    hitPoints = 100;
    attackDamage = 30;
    energyPoints = 50;
    std::cout << "\033[32m💎 [DiamondTrap] Unit deployed: " << name << " (default configuration)\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name)
{
    hitPoints = 100;
    attackDamage = 30;
    energyPoints = 50;
    std::cout << "\033[36m💎 [DiamondTrap] Custom unit initialized: " << name << "\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    this->name = other.name;
    std::cout << "\033[34m💎 [DiamondTrap] Clone unit created from: " << other.name << "\033[0m" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other) {
        ClapTrap::operator=(other);
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        this->name = other.name;
    }
    std::cout << "\033[35m💎 [DiamondTrap] Configuration copied to: " << this->name << "\033[0m" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "\033[31m💎 [DiamondTrap] Unit " << name << " has been decommissioned.\033[0m" << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount) {
    hitPoints -= amount;
    if ((int)hitPoints < 0)
        hitPoints = 0;
    std::cout << "\033[91m💢 [DiamondTrap] " << name << " sustained " << amount
              << " damage! [HP: " << hitPoints << "]\033[0m" << std::endl;
}

void DiamondTrap::beRepaired(unsigned int amount) {
    if (energyPoints > 0 && hitPoints > 0) {
        hitPoints += amount;
        energyPoints--;
        std::cout << "\033[92m🛠️  [DiamondTrap] " << name << " initiated self-repair: +" << amount
                  << " HP! [HP: " << hitPoints << ", EP: " << energyPoints << "]\033[0m" << std::endl;
    } else {
        std::cout << "\033[31m❌ [DiamondTrap] " << name << " failed to repair (insufficient energy or offline).\033[0m" << std::endl;
    }
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "\033[95m💎 [DiamondTrap] My name is " << name << " and my ClapTrap name is " << ClapTrap::name << "\033[0m" << std::endl;
}
