//
// Created by supersayan on 4/6/23.
//

#include "Ice.hpp"

Ice::Ice()
: AMateria("ice")
{}

AMateria* Ice::clone()
{
	AMateria *clone = new Ice;
	return (clone);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << /* todo: add target here << */ std::endl;
}