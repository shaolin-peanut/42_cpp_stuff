//
// Created by supersayan on 4/11/23.
//

#ifndef INC_42_CPP_STUFF_IMATERIASOURCE_HPP
#define INC_42_CPP_STUFF_IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource {
public:
	IMateriaSource();
	~IMateriaSource();
	virtual void learnMateria(AMateria* learn)  = 0;
	virtual AMateria* createMateria(std::string type) const = 0;
};

#endif //INC_42_CPP_STUFF_IMATERIASOURCE_HPP
