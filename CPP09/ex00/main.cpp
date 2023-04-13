//
// Created by Samuel Bars on 4/13/23.
//

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./bitcoin <amount>" << std::endl;
		return (1);
	}

	try {
		BitcoinExchange exchange(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
