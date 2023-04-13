//
// Created by Samuel Bars on 4/13/23.
//

#include "Warlock.hpp"

// PRIVATE
Warlock::Warlock()
: _name("default"), _title("default")
{}

// PUBLIC
Warlock::Warlock(const int &name, const int &title)
: _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

// PRIVATE
Warlock::Warlock(Warlock const &copy)
: _name(copy._name), _title(copy._title)
{}

// PRIVATE
Warlock& Warlock::operator=(Warlock const &copy) {
	_name = copy._name;
	_title = copy._title;
	return *this;
}

// PUBLIC
Warlock::~Warlock() {
	std::cout << _name << ": My job here is done!" << std::endl;
}

std::string& Warlock::getName() const {
	return _name;
}

std::string& Warlock::getTitle() const {
	return _title;
}
void Warlock::setTitle(std::string const &title) {
	_title = title;}

void Warlock::introduce() const {
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}