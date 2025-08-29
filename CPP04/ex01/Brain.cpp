#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "\033[1;32m[+] Brain created 🧠\033[0m" << std::endl;
}

Brain::Brain(const Brain& other) : Brain()
{

}

Brain& Brain::operator=(const Brain& other)
{

}

Brain::~Brain()
{
    std::cout << "\033[1;31m[-] Brain destroyed 🧠\033[0m" << std::endl;
}