#pragma once

#include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    virtual ~Animal();
    virtual void makeSound() const = 0;
    virtual std::string getType() const;
};
