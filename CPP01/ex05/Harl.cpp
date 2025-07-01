#include "Harl.hpp"
#include <iostream>

void Harl::debug( void )
{
    std::cout << "\033[1;34m[DEBUG] 🛠️  \033[0m"
              << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
              << std::endl;
}

void Harl::info( void )
{
    std::cout << "\033[1;36m[INFO] ℹ️  \033[0m"
              << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
              << std::endl;
}

void Harl::warning( void )
{
    std::cout << "\033[1;33m[WARNING] ⚠️  \033[0m"
              << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
              << std::endl;
}

void Harl::error( void )
{
    std::cout << "\033[1;31m[ERROR] ❌  \033[0m"
              << "This is unacceptable! I want to speak to the manager now."
              << std::endl;
}

void Harl::complain( std::string level )
{
    void (Harl::*functions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            return (this->*functions[i])();
    }

    std::cout << "\033[1;90m[🤷 Unknown] Likely grumbling over trivial issues.\033[0m" << std::endl;
}

Harl::Harl() {}
Harl::~Harl() {}
