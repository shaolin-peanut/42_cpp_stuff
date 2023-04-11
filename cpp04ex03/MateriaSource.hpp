//
// Created by supersayan on 4/11/23.
//

#ifndef INC_42_CPP_STUFF_MATERIASOURCE_HPP
#define INC_42_CPP_STUFF_MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria* skill_stack[4];
public:
	MateriaSource();
	~MateriaSource();

	virtual void	learnMateria(AMateria *learn);
	virtual AMateria* createMateria(std::string type) const;
};


#endif //INC_42_CPP_STUFF_MATERIASOURCE_HPP
