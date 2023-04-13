//
// Created by supersayan on 4/6/23.
//

#include "Cure.hpp"

Cure::Cure()
: AMateria("cure")
{}

Cure::~Cure()
{}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{ // todo: add target name
	std::cout << "* heals " << target.getName() << " *" << std::endl;
}
