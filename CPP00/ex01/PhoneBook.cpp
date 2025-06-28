#include "PhoneBook.hpp"
#include "String.hpp"

PhoneBook::PhoneBook() : _nbContact(0)
{

}

PhoneBook::~PhoneBook()
{

}

int	PhoneBook::getNbContact() const
{
    return this->_nbContact;
}

void PhoneBook::addContact(Contact newContanct)
{
    int index = _nbContact % 8;
    _contact[index] = newContanct;
}

void PhoneBook::start()
{
    std::string input;

    while (true)
    {
        std::cout << "What do you want: ";
        getline(std::cin, input);
        input = strToUpper(input);
        if (input == "ADD")
        {
            Contact tmp;
            std::cout << "First Name: ";
            getline(std::cin, input);
            if (std::cin.eof())
            {
                std::cout << "Bye :)" << std::endl;
            }
            tmp.setFirstName(input);
            std::cout << "Last Name: ";
            getline(std::cin, input);
            if (std::cin.eof())
            {
                std::cout << "Bye :)" << std::endl;
            }
            tmp.setLastName(input);
            std::cout << "Nick Name: ";
            getline(std::cin, input);
            if (std::cin.eof())
            {
                std::cout << "Bye :)" << std::endl;
            }
            tmp.setNickName(input);
            std::cout << "Phone Number: ";
            getline(std::cin, input);
            if (std::cin.eof())
            {
                std::cout << "Bye :)" << std::endl;
            }
            tmp.setPhoneNumber(input);
            std::cout << "Darkest Secret: ";
            getline(std::cin, input);
            if (std::cin.eof())
            {
                std::cout << "Bye :)" << std::endl;
            }
            tmp.setDarkestSecret(input);
            addContact(tmp);
        }
        else if (input == "SEARCH")
        {

        }
        else if (input == "EXIT")
        {
            break;
        }
        else if (std::cin.eof()) {
            std::cout << "Bye :)" << std::endl;
        }
        else {
            std::cout << "Command not found" << std::endl;
        }
    }
}