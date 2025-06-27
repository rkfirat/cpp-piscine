#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{

}

PhoneBook::~PhoneBook()
{

}

int	PhoneBook::getNbContact() const
{
    return this->_nbContact;
}

void PhoneBook::start()
{
    std::string input;

    while (true)
    {
        getline(std::cin, input);
    }
}