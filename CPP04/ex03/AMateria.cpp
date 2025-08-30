#include "AMateria.hpp"

AMateria::AMateria() 
{

}

AMateria::AMateria(std::string const& type) : type(type)
{

}

AMateria::~AMateria()
{

}

void AMateria::use(ICharacter& target)
{
	(void)target;
}

std::string const & AMateria::getType() const
{
	return this->type;
}
