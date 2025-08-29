#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
private:
public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();
    void makeSound() const;
    std::string getType() const;
};