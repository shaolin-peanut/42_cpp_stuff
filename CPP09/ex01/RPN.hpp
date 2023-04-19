//
// Created by Samuel Bars on 4/19/23.
//

#ifndef INC_42_CPP_STUFF_RPN_HPP
#define INC_42_CPP_STUFF_RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>

class RPN
{
private:
	RPN();
	RPN(RPN const &copy);
	RPN &operator=(RPN const &copy);
public:
	RPN(std::string const &str);
	~RPN();

	int evaluate(std::string const &str);
};


#endif //INC_42_CPP_STUFF_RPN_HPP
