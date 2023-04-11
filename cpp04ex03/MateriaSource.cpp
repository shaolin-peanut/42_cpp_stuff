//
// Created by supersayan on 4/11/23.
//

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		skill_stack[i] = nullptr;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (skill_stack[i] != nullptr)
			delete skill_stack[i];
	}
}

void	MateriaSource::learnMateria(AMateria *learn) {
	for (int i = 0; i < 4; i++) {
		if (skill_stack[i] != nullptr) {
			skill_stack[i] = learn;
			return ;
		}
	}
	std::cout << "No space left in MateriaSource->skill_stack (max 4 items)"
	<< std::endl;
}

AMateria* MateriaSource::createMateria(std::string type) const {
	for (int i = 0; i < 4; i++) {
		if (skill_stack[i]->getType() == type)
			return (skill_stack[i]->clone());
	}
	return (nullptr);
}