#pragma once

#include <iostream>

class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    ~WrongAnimal();  // ❌ Missing virtual - DANGEROUS!
    void makeSound() const;  // ❌ Not virtual - will cause slicing
    std::string getType() const;
};
