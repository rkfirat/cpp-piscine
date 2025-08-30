#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    type = "WrongCat";
    std::cout << "\033[1;31m[+] WrongCat constructor called 🐱\033[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "\033[1;31m[+] WrongCat copy constructor called 🐱\033[0m" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
        std::cout << "\033[1;31m[=] WrongCat assignment operator called 🐱\033[0m" << std::endl;
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "\033[1;31m[-] WrongCat destructor called 🐱\033[0m" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "\033[1;31m🐱 Wrong Meow~ 🐾\033[0m" << std::endl;
}

std::string WrongCat::getType() const {
    return type;
}
