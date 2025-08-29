#include "Cat.hpp"


Cat::Cat() : Animal() {
    type = "Cat";
    std::cout << "\033[1;36m[+] Cat constructor called 🐱\033[0m" << std::endl;
}

Cat::~Cat() {
    std::cout << "\033[1;31m[-] Cat destructor called 🐱\033[0m" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "\033[1;35m🐱 Meow~ 🐾\033[0m" << std::endl;
}

std::string Cat::getType() const {
    return type;
}