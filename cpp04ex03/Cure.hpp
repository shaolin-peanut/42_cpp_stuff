//
// Created by supersayan on 4/6/23.
//

#ifndef INC_42_CPP_STUFF_CURE_HPP
#define INC_42_CPP_STUFF_CURE_HPP


#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	// todo: add missing OCC functions

	virtual AMateria* clone();
	virtual void use(ICharacter& target);
};


#endif //INC_42_CPP_STUFF_CURE_HPP
