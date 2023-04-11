//
// Created by supersayan on 4/6/23.
//

#include "Cure.hpp"

Cure::Cure()
: AMateria("cure")
{}


AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{ // todo: add target name
	std::cout << "* heals <name's wounds *" << std::endl;
}