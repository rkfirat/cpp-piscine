#pragma once

#include <iostream>

class Weapon
{
private:
    std::string type;
public:
    Weapon(std::string name);
    ~Weapon();
    void setType(std::string name);
    std::string getType() const;
};