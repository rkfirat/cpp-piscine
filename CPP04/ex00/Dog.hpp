#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
private:
public:
    Dog();
    ~Dog();
    void makeSound() const;
    std::string getType() const;
};