#include "Harl.hpp"

void Harl::debug( void )
{
    std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
    std::cout << "[INFO] cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}
void Harl::error( void )
{
    std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int id = -1;
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            id = i; 
    }
    switch (id)
    {
    case 0:
        Harl::debug();
        Harl::info();
        Harl::warning();
        Harl::error();
        break;
    case 1:
        Harl::info();
        Harl::warning();
        Harl::error();
        break;
    case 2:
        Harl::warning();
        Harl::error();
        break;
    case 3:
        Harl::error();
        break;    
    default:
        std::cout << "[ Probably complaining about insignificant problem. ]" << std::endl;
        break;
    }
}

Harl::Harl()
{

}

Harl::~Harl()
{

}
