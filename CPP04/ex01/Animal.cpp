#include "Animal.hpp"


Animal::Animal() : type("Animal")
{
    std::cout << "\033[1;32m[+] Animal created:\033[0m " << type << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
    std::cout << "\033[1;36m[+] Animal copied:\033[0m " << type << std::endl;
}
Animal& Animal::operator=(const Animal& other)
{
    if (this != &other) {
        this->type = other.type;
        std::cout << "\033[1;33m[=] Animal assigned:\033[0m " << type << std::endl;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "\033[1;31m[-] Animal destroyed:\033[0m " << type << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "\033[1;33m🐾 Generic animal sound...\033[0m" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}