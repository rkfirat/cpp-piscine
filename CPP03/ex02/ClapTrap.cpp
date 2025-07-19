#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("robot"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "\033[32m🤖 ClapTrap default constructor called for " << name << "\033[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "\033[36m🔧 ClapTrap named constructor called for " << name << "\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
    std::cout << "\033[34m📋 ClapTrap copy constructor called for " << name << "\033[0m" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other) {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "\033[35m📝 ClapTrap assignment operator called for " << name << "\033[0m" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "\033[31m💀 ClapTrap destructor called for " << name << "\033[0m" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if (energyPoints > 0 && hitPoints > 0) {
        std::cout << "\033[33m⚔️  ClapTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!\033[0m" << std::endl;
        energyPoints--;
    } else {
        std::cout << "\033[31m❌ ClapTrap " << name << " can't attack! (no energy or dead)\033[0m" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    hitPoints -= amount;
    if (hitPoints < 0)
        hitPoints = 0;
    std::cout << "\033[91m💢 ClapTrap " << name << " takes " << amount
              << " points of damage! Remaining HP: " << hitPoints << "\033[0m" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints > 0 && hitPoints > 0) {
        hitPoints += amount;
        energyPoints--;
        std::cout << "\033[92m🛠️  ClapTrap " << name << " repairs " << amount
                  << " hit points! New HP: " << hitPoints << "\033[0m" << std::endl;
    } else {
        std::cout << "\033[31m❌ ClapTrap " << name << " can't repair! (no energy or dead)\033[0m" << std::endl;
    }
}
