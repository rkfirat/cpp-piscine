#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
private:
public:
    Cat();
    ~Cat();
    void makeSound() const;
    std::string getType() const;
};