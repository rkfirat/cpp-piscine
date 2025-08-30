#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : count(0)
{
    for (size_t i = 0; i < 4; i++)
    {
        this->inventory[i] = NULL;
    }
}
MateriaSource::MateriaSource(const MateriaSource &other)
{
    this->count = other.count;
    for (size_t i = 0; i < 4; i++)
    {
        this->inventory[i] = NULL;
    }
    for (size_t i = 0; i < this->count; i++)
    {
        this->inventory[i] = other.inventory[i]->clone();
    }
}
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (size_t i = 0; i < 4; i++)
        {
            delete this->inventory[i];
            this->inventory[i] = NULL;
        }
        this->count = other.count;
        for (size_t i = 0; i < this->count; i++)
        {
            this->inventory[i] = other.inventory[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (size_t i = 0; i < 4; i++)
	{
		delete this->inventory[i];
		this->inventory[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria *mat)
{
    if (this->count < 4 && mat)
		inventory[count++] = mat;
}

AMateria * MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i) 
	{
		if (inventory[i] && inventory[i]->getType() == type)
			return inventory[i]->clone();
	}
	return NULL;
}
