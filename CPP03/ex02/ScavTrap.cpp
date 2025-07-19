#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("robot"), hitPoints(100), energyPoints(50), attackDamage(20)
{
    std::cout << "\033[32m🤖 [ScavTrap] Unit deployed: " << name << " (default configuration)\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), hitPoints(100), energyPoints(50), attackDamage(20)
{
    std::cout << "\033[36m🔧 [ScavTrap] Custom unit initialized: " << name << "\033[0m" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "\033[34m📋 [ScavTrap] Clone unit created from: " << other.name << "\033[0m" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other) {
        ClapTrap::operator=(other);
        hitPoints = 100;
        energyPoints = 50;
        attackDamage = 20;
    }
    std::cout << "\033[35m📝 [ScavTrap] Configuration copied to: " << this->name << "\033[0m" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "\033[31m💀 [ScavTrap] Unit " << name << " has been decommissioned.\033[0m" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (energyPoints > 0 && hitPoints > 0) {
        std::cout << "\033[33m⚔️  [ScavTrap] " << name << " launches an attack on " << target
                  << ", dealing " << attackDamage << " damage! (EP--)\033[0m" << std::endl;
        energyPoints--;
    } else {
        std::cout << "\033[31m❌ [ScavTrap] " << name << " attempted to attack but failed (out of energy or destroyed).\033[0m" << std::endl;
    }
}

void ScavTrap::takeDamage(unsigned int amount) {
    hitPoints -= amount;
    if ((int)hitPoints < 0)
        hitPoints = 0;
    std::cout << "\033[91m💢 [ScavTrap] " << name << " sustained " << amount
              << " damage! [HP: " << hitPoints << "]\033[0m" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
    if (energyPoints > 0 && hitPoints > 0) {
        hitPoints += amount;
        energyPoints--;
        std::cout << "\033[92m🛠️  [ScavTrap] " << name << " initiated self-repair: +" << amount
                  << " HP! [HP: " << hitPoints << ", EP: " << energyPoints << "]\033[0m" << std::endl;
    } else {
        std::cout << "\033[31m❌ [ScavTrap] " << name << " failed to repair (insufficient energy or offline).\033[0m" << std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "\033[94m🛡️  [ScavTrap] " << name << " has entered *Gate Keeper Mode*. Defensive protocols online.\033[0m" << std::endl;
}
