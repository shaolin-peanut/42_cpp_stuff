//
// Created by supersayan on 4/6/23.
//

#ifndef INC_42_CPP_STUFF_ICE_HPP
#define INC_42_CPP_STUFF_ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	virtual ~Ice();
	// todo: add the rest of the OCC

	AMateria* clone() const;
	void use(ICharacter& target);
};


#endif //INC_42_CPP_STUFF_ICE_HPP
