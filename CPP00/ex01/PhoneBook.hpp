#pragma once

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
private:
	int		_nbContact;
	Contact	_contact[8];
public:
	PhoneBook();
	~PhoneBook();
	int	getNbContact() const;
	void start();
};

