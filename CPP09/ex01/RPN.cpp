//
// Created by Samuel Bars on 4/19/23.
//

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const &copy) { (void)copy; }

RPN &RPN::operator=(RPN const &copy) {
	(void)copy;
	return *this;
}

RPN::RPN(std::string const &str)
{
	if (!str.empty()) {
		int ret = evaluate(str);
		if (ret != -1)
			std::cout << "Result: " << ret << std::endl;
		else
			throw std::invalid_argument("Usage: ./RPN \"numbers operators\"");
	}
	else
		std::cout << "Error: Invalid input" << std::endl;
}

RPN::~RPN() {}

int RPN::evaluate(const std::string &str)
{
	std::istringstream ss(str);
	std::stack<int> pile;
	std::string token;

	while (std::getline(ss, token, ' '))
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
            if (pile.size() < 2) {
                std::cout << "Error: Please input numbers BEFORE operators" << std::endl;
                return (-1); // return an error code
            }
			int a = pile.top();
			pile.pop();
			int b = pile.top();
			pile.pop();

			if (token == "+") {
				pile.push(b + a);
			} else if (token == "-") {
				pile.push(b - a);
			} else if (token == "*") {
				pile.push(b * a);
			} else if (token == "/") {
				pile.push(b / a);
			}
		}
		else if (token.length() == 1 && isdigit(token[0])) {
			int digit = token[0] - '0';
			if (digit >= 0 && digit <= 9) {
				pile.push(digit);
			} else {
				std::cout << "Invalid digit range" << std::endl;
			}
		}
		else {
			std::cout << "Error: Invalid input" << std::endl;
			return (-1); // return an error code
		}
	}

	return pile.top();
}
