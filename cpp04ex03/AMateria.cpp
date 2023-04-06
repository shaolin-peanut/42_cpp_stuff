//
// Created by supersayan on 4/6/23.
//

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
: _type(type)
{}

std::string const & AMateria::getType() const {
	return _type;
}

