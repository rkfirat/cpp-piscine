#include "PhoneBook.hpp"
#include <cstdlib>

PhoneBook::PhoneBook() : _nbContact(0) {}

PhoneBook::~PhoneBook() {}

int PhoneBook::getNbContact() const {
    return this->_nbContact;
}

void PhoneBook::addContact(Contact newContact) {
    int index = getNbContact() % 8;
    _contact[index] = newContact;
    _nbContact++;
}

static void printHeader() {
    std::cout << "\033[1;36m================ PHONEBOOK ================\033[0m" << std::endl;
    std::cout << "\033[1;32mCommands: ADD | SEARCH | EXIT\033[0m" << std::endl;
}

static void printGoodbye() {
    std::cout << "\033[1;31mBye :)\033[0m" << std::endl;
}

void PhoneBook::start() {
    std::string input;

    printHeader();
    while (true) {
        input.clear();
        std::cin.clear();
        std::cout << "\n\033[1;33mWhat do you want:\033[0m ";
        std::getline(std::cin, input);
        input = strToUpper(input);

        if (input.empty())
            continue;
        if (std::cin.eof()) {
            input.clear();
            std::cin.clear();
            printGoodbye();
            break;
        }

        if (input == "ADD") {
            std::string tmpContact;
            Contact tmp;

            std::cout << "First Name: ";
            std::getline(std::cin, tmpContact);
            if (std::cin.eof())
            {
                tmpContact.clear();
                std::cin.clear();
                return printGoodbye();
            }
            tmp.setFirstName(tmpContact);
            std::cout << "Last Name: ";
            std::getline(std::cin, tmpContact);
            if (std::cin.eof())
            {
                tmpContact.clear();
                std::cin.clear();
                return printGoodbye();
            }
            tmp.setLastName(tmpContact);
            std::cout << "Nick Name: ";
            std::getline(std::cin, tmpContact);
            if (std::cin.eof())
            {
                tmpContact.clear();
                std::cin.clear();
                return printGoodbye();
            }
            tmp.setNickName(tmpContact);
            std::cout << "Phone Number: ";
            std::getline(std::cin, tmpContact);
            if (std::cin.eof())
            {
                tmpContact.clear();
                std::cin.clear();
                return printGoodbye();
            }
            tmp.setPhoneNumber(tmpContact);
            std::cout << "Darkest Secret: ";
            std::getline(std::cin, tmpContact);
            if (std::cin.eof())
            {
                tmpContact.clear();
                std::cin.clear();
                return printGoodbye();
            }
            tmp.setDarkestSecret(tmpContact);
            addContact(tmp);
            std::cout << "\033[1;32mContact added successfully!\033[0m" << std::endl;
        }
        else if (input == "SEARCH") {
            int total = getNbContact() > 8 ? 8 : getNbContact();
            if (total == 0) {
                input.clear();
                std::cin.clear();
                std::cout << "\033[1;31mNo contacts found.\033[0m" << std::endl;
                continue;
            }
            std::cout << "\033[1;34m"
                    << std::setw(10) << "Index" << " | "
                    << std::setw(10) << "First Name" << " | "
                    << std::setw(10) << "Last Name" << " | "
                    << std::setw(10) << "Nick Name"
                    << "\033[0m" << std::endl;
            for (int i = 0; i < total; ++i) {
                std::cout << std::setw(10) << i << " | "
                << std::setw(10) << truncate(_contact[i].getFirstName(), 9) << " | "
                << std::setw(10) << truncate(_contact[i].getLastName(), 9) << " | "
                << std::setw(10) << truncate(_contact[i].getNickName(), 9)
                << std::endl;
            }
            std::cout << "\n\033[1;33mEnter the index of the contact to view details:\033[0m ";
            std::string indexInput;
            std::getline(std::cin, indexInput);

            if (std::cin.eof()) {
                input.clear();
                std::cin.clear();
                return printGoodbye();
            }

            if (indexInput.empty()) {
                std::cout << "\033[1;31mInput cannot be empty. Try again.\033[0m" << std::endl;
            }
            else if (indexInput.find_first_not_of("0123456789") != std::string::npos) {
                std::cout << "\033[1;31mInvalid input. Not a number.\033[0m" << std::endl;
            }
            else {
                int index = std::atoi(indexInput.c_str());
                if (index < 0 || index >= total) {
                    std::cout << "\033[1;31mIndex out of range. Try again.\033[0m" << std::endl;
                }
                else {
                    const Contact& c = _contact[index];
                    std::cout << "\033[1;36m========== Contact Details ==========\033[0m\n";
                    std::cout << "First Name     : " << c.getFirstName() << std::endl;
                    std::cout << "Last Name      : " << c.getLastName() << std::endl;
                    std::cout << "Nick Name      : " << c.getNickName() << std::endl;
                    std::cout << "Phone Number   : " << c.getPhoneNumber() << std::endl;
                    std::cout << "Darkest Secret : " << c.getDarkestSecret() << std::endl;
                    std::cout << "\033[1;36m=====================================\033[0m" << std::endl;
                }
            }
        }
        else if (input == "EXIT") {
            input.clear();
            std::cin.clear();
            printGoodbye();
            break;
        }
        else {
            std::cout << "\033[1;31mCommand not found. Try again.\033[0m" << std::endl;
        }
    }
}
