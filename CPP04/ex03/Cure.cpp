#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{

}

Cure::~Cure() {}

Cure::Cure(const Cure &copy) 
{
	this->type = copy.type;
}

Cure& Cure::operator=(const Cure& copy) 
{
	if (this != &copy)
		this->type = copy.type;
	return *this;	
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
	return new Cure();
}