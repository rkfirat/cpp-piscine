#include "Dog.hpp"

Dog::Dog() : Animal() {
    brain = new Brain();
    type = "Dog";
    std::cout << "\033[1;36m[+] Dog constructor called 🐶\033[0m" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    brain = new Brain(*other.brain);
    type = other.type;
    std::cout << "\033[1;36m[+] Dog copy constructor called 🐶\033[0m" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
        type = other.type;
        std::cout << "\033[1;33m[=] Dog assignment operator called 🐶\033[0m" << std::endl;
    }
    return *this;
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
