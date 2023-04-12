//
// Created by supersayan on 4/6/23.
//

#include "Ice.hpp"

Ice::Ice()
: AMateria("ice")
{}

Ice::~Ice()
{
	AMateria::~AMateria();
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "*  shoots an ice bolt at " << target.getName() <<  " " << std::endl;
}