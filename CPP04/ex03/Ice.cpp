#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{

}

Ice::~Ice() {}

Ice::Ice(const Ice &copy) 
{
	this->type = copy.type;
}

Ice& Ice::operator=(const Ice& copy) 
{
	if (this != &copy)
		this->type = copy.type;
	return *this;	
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice();
}