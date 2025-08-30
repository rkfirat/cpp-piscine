#include "Character.hpp"

Character::Character(std::string name) : name(name)
{
    for (size_t i = 0; i < 4; i++)
    {
        this->inventory[i] = NULL;
    }
}
Character::Character(const Character &other)
{
    this->name = other.name;
    for (size_t i = 0; i < 4; i++)
    {
        if (other.inventory[i])
            this->inventory[i] = other.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
}
Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        for (size_t i = 0; i < 4; i++)
        {
            delete this->inventory[i];
            this->inventory[i] = NULL;
        }
        for (size_t i = 0; i < 4; i++)
        {
            if (other.inventory[i])
                this->inventory[i] = other.inventory[i]->clone();
            else
                this->inventory[i] = NULL;
        }
        this->name = other.name;
    }
    return *this;
}
Character::~Character()
{
    for (size_t i = 0; i < 4; i++)
    {
        delete inventory[i];
        this->inventory[i] = NULL;
    }
}

std::string const &Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria *mat)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = mat;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
    {
		this->inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (this->inventory[idx])
    {
		this->inventory[idx]->use(target);
    }
}