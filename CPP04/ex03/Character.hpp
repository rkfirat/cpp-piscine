#pragma once 
#include "ICharacter.hpp"

class ICharacter;
class AMateria;

class Character : public ICharacter
{
private:
	std::string name;
	AMateria* inventory[4];
public:
	Character(std::string name);
	Character(const Character &other);
	Character& operator=(const Character& other);
	~Character();

	std::string const & getName() const;
	void equip(AMateria* mat);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

};