#pragma once

#include <iostream>

class Contact
{
private:
	std::string		_firstName;
	std::string		_lastName;
	std::string		_nickName;
	std::string		_phoneNumber;
	std::string		_darkestSecret;
public:
	Contact();
	~Contact();
};

class PhoneBook
{
private:
	int		_nbContact;
	Contact	_contact[8];
public:
	PhoneBook();
	~PhoneBook();
};

