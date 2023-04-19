//
// Created by Samuel Bars on 4/19/23.
//

#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
	{
		std::cout << "Usage: ./RPN \"numbers operators\"" << std::endl;
		return (0);
	}
	else
	{
		RPN rpn(argv[1]);
	}
	return (0);
}