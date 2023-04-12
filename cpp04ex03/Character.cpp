//
// Created by supersayan on 4/6/23.
//

#include "Character.hpp"

Character::Character(std::string name)
: _name(name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = 0;
	std::cout << "Character constructor called: " << name << std::endl;
}

Character::Character(Character &copy)
: ICharacter(copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++) {
			if (inventory[i])
				inventory[i] = 0;
			if (copy.inventory[i])
				inventory[i] = copy.inventory[i]->clone();
		}
	}
	std::cout << "Character copy constructor called" << std::endl;
}

Character &Character::operator=(Character &rhs) {
	if (this != &rhs) {
		ICharacter::operator=(rhs);
		for (int i = 0; i < 4; i++) {
			if (inventory[i])
				inventory[i] = 0;
			if (rhs.inventory[i])
				inventory[i] = rhs.inventory[i]->clone();
		}
	}
	std::cout << "Character assignment constructor called" << std::endl;
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++) {
		if (inventory[i] != 0)
			delete inventory[i];
	}
	std::cout << "Character destructor called" << std::endl;
}

const std::string &Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (inventory[i] == 0 && m != 0) {
			inventory[i] = m;
			std::cout << _name << " equipped with " << m->getType() << std::endl;
			return ;
		}
	}
}

void Character::unequip(int idx) {
	if (inventory[idx] != 0)
	{
		// todo: how do I keep unequiped materias addresses to delete later?
		// maybe do my malloc midllemen
		delete inventory[idx];
		inventory[idx] = 0;
	}
}

void Character::use(int idx, ICharacter &target) {
	if (inventory[idx])
		inventory[idx]->use(target);
}