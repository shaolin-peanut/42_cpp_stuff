//
// Created by supersayan on 4/6/23.
//

#ifndef INC_42_CPP_STUFF_AMATERIA_HPP
#define INC_42_CPP_STUFF_AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string	_type;
public:
	AMateria(std::string const & type);
	virtual ~AMateria();
	// add stuff
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};


#endif //INC_42_CPP_STUFF_AMATERIA_HPP
