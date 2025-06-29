#pragma once

#include <iostream>
#include <iomanip>
#include "Contact.hpp"
#include "String.hpp"

class PhoneBook
{
private:
	int		_nbContact;
	Contact	_contact[8];
public:
	PhoneBook();
	~PhoneBook();
	int	getNbContact() const;
	void addContact();
	void start();
	void addContact(Contact newContanct);
};

