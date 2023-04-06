//
// Created by supersayan on 4/6/23.
//

#ifndef INC_42_CPP_STUFF_CHARACTER_HPP
#define INC_42_CPP_STUFF_CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
public:
	Character(std::string name);
	Character(Character& copy);
	Character&	operator=(Character& rhs);
	virtual ~Character();

	virtual std::string const & getName();
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
private:
	std::string	_name;
	AMateria*	inventory[4];
	// inventory
};


#endif //INC_42_CPP_STUFF_CHARACTER_HPP
