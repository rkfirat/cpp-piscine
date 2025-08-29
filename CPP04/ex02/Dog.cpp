#include "Dog.hpp"

Dog::Dog() : Animal() {
    brain = new Brain();
    type = "Dog";
    std::cout << "\033[1;36m[+] Dog constructor called 🐶\033[0m" << std::endl;
}

Dog::~Dog() {
    delete brain;
    std::cout << "\033[1;31m[-] Dog destructor called 🐶\033[0m" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "\033[1;34m🐶 Woof! Woof! 🐾\033[0m" << std::endl;
}

std::string Dog::getType() const {
    return type;
}
