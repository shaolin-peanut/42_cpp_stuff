//
// Created by supersayan on 4/6/23.
//

#ifndef INC_42_CPP_STUFF_CHARACTER_HPP
#define INC_42_CPP_STUFF_CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
public:
	Character(std::string name);
	Character(Character& copy);
	Character&	operator=(Character& rhs);
	virtual ~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
private:
	std::string	_name;
	AMateria*	inventory[4];
};


#endif //INC_42_CPP_STUFF_CHARACTER_HPP
