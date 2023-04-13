//
// Created by Samuel Bars on 4/13/23.
//

#ifndef INC_42_CPP_STUFF_WARLOCK_HPP
#define INC_42_CPP_STUFF_WARLOCK_HPP

#include <iostream>

class Warlock
{
private:
	std::string _name;
	std::string _title;
	Warlock();
	Warlock(Warlock const &copy);
	Warlock &operator=(Warlock const &copy);
public:
	Warlock(std::string const &name, std::string const &title);
	~Warlock();

	std::string &getName() const;
	std::string &getTitle() const;
	void setTitle(std::string const &title);
	void introduce() const;
};


#endif //INC_42_CPP_STUFF_WARLOCK_HPP
