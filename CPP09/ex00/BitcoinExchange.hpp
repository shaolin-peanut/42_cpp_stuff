//
// Created by Samuel Bars on 4/13/23.
//

#ifndef INC_42_CPP_STUFF_BITCOINEXCHANGE_HPP
#define INC_42_CPP_STUFF_BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <regex>

class BitcoinExchange
{
private:
	std::map<std::string, float> _rates;
public:
	BitcoinExchange();
	BitcoinExchange(std::string filename);
	~BitcoinExchange();
};


#endif //INC_42_CPP_STUFF_BITCOINEXCHANGE_HPP
