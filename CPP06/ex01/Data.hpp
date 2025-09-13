#pragma once

#include <iostream>

class Data
{
private:
    int         number;
    std::string text;
public:
    Data();
    Data(int number, std::string text);
    Data(const Data & other);
    Data &operator=(const Data & other);
    ~Data();
    int getNumber() const;
    std::string getText() const;
};
