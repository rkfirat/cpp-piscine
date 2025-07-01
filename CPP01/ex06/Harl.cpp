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
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int id = -1;

    for (int i = 0; i < 4; ++i)
    {
        if (levels[i] == level)
        {
            id = i;
            break;
        }
    }

    switch (id)
    {
    case 0:
        this->debug();
    case 1:
        this->info();
    case 2:
        this->warning();
    case 3:
        this->error();
        break;
    default:
        std::cout << "\033[1;90m[🤷 Unknown] Probably complaining about insignificant problem.\033[0m" << std::endl;
        break;
    }
}

Harl::Harl() {}

Harl::~Harl() {}
