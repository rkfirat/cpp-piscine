#include "Cat.hpp"


Cat::Cat() : Animal() {
    brain = new Brain();
    type = "Cat";
    std::cout << "\033[1;36m[+] Cat constructor called 🐱\033[0m" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "\033[1;36m[+] Cat copy constructor called 🐱\033[0m" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        std::cout << "\033[1;33m[=] Cat assignment operator called 🐱\033[0m" << std::endl;
    }
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "\033[1;31m[-] Cat destructor called 🐱\033[0m" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "\033[1;35m🐱 Meow~ 🐾\033[0m" << std::endl;
}

std::string Cat::getType() const {
    return type;
}