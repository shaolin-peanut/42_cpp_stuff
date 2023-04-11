//
// Created by supersayan on 4/6/23.
//

#include "Character.hpp"

Character::Character(std::string name)
: _name(name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = nullptr;
}

Character::Character(Character &copy) {
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++) {
			if (inventory[i])
				inventory[i] = nullptr;
			if (copy.inventory[i])
				inventory[i] = copy.inventory[i]->clone();
		}
	}
}

Character &Character::operator=(Character &rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 4; i++) {
			if (inventory[i])
				inventory[i] = nullptr;
			if (rhs.inventory[i])
				inventory[i] = rhs.inventory[i]->clone();
		}
	}
	return *this;
}

const std::string &Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (inventory[i] == nullptr)
			inventory[i] = m;
	}
}

void Character::unequip(int idx) {
	if (inventory[idx] != nullptr)
	{
		// todo: how do I keep unequiped materias addresses to delete later?
		// maybe do my malloc midllemen
		inventory[idx] = nullptr;
	}
}

void Character::use(int idx, ICharacter &target) {
	if (inventory[idx])
		inventory[idx]->use(target);
}