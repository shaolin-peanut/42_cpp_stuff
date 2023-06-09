//
// Created by supersayan on 4/11/23.
//

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		skill_stack[i] = 0;
	std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++) {
		if (skill_stack[i] != 0)
			delete skill_stack[i];
	}
	std::cout << "MateriaSource destructor called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria *learn) {
	for (int i = 0; i < 4; i++) {
		if (skill_stack[i] == 0) {
			skill_stack[i] = learn;
			std::cout << "learned " << learn->getType() << std::endl;
			return ;
		}
	}
	std::cout << "No space left in MateriaSource->skill_stack (max 4 items)"
	<< std::endl;
}

AMateria* MateriaSource::createMateria(std::string const type) {
	for (int i = 0; i < 4; i++) {
		if (skill_stack[i]->getType() == type) {

			return (skill_stack[i]->clone());
		}
	}
	return (0);
}