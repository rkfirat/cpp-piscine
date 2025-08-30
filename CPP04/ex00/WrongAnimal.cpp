#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "\033[1;32m[+] WrongAnimal created:\033[0m " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
    std::cout << "\033[1;36m[+] WrongAnimal copied:\033[0m " << type << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
    {
        this->type = other.type;
        std::cout << "\033[1;33m[=] WrongAnimal assigned:\033[0m " << type << std::endl;
    }
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "\033[1;31m[-] WrongAnimal destroyed:\033[0m " << type << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "\033[1;33m🐾 Wrong generic animal sound...\033[0m" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}

