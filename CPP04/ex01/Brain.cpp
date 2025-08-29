#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "\033[1;32m[+] Brain created 🧠\033[0m" << std::endl;
}

Brain::Brain(const Brain& other)
{
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = other.ideas[i];
    }
    std::cout << "\033[1;32m[+] Brain copy constructor called 🧠\033[0m" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = other.ideas[i];
        }
        std::cout << "\033[1;33m[=] Brain assignment operator called 🧠\033[0m" << std::endl;
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "\033[1;31m[-] Brain destroyed 🧠\033[0m" << std::endl;
}