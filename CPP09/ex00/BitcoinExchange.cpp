//
// Created by Samuel Bars on 4/13/23.
//

#include "BitcoinExchange.hpp"

static bool is_valid_date(const std::string &date)
{
	if (date == "date")
		return true;
	// todo: check validity without regex, split string by - and check each part
	if (date.size() != 10)
		return false;

	std::istringstream ss(date);
	std::string year, month, day;
	std::getline(ss, year, '-');
	if (year.size() != 4 || year[0] < 0 || year[0] > 2)
		return false;
	std::getline(ss, month, '-');
	if (month.size() != 2 || month[0] < 0 || month[0] > 1 || month[1] < 0 || month[1] > 9)
		return false;
	std::getline(ss, day, '-');
	if (day.size() != 2 || day[0] < 0 || day[0] > 3 || day[1] < 0 || day[1] > 9)
		return false;
	return true;
}

bool is_valid_price(const std::string &price)
{
	if (price == "price")
		return true;
	if (price < "0" || price > "1000")
		return false;
//	for (int i = 0; i < (int) price.length(); i++)
//	{
//		if (price[i] < '0' || price[i] > '9')
//			return false;
//	}
	return (true);
}

BitcoinExchange::BitcoinExchange() {
	throw std::runtime_error("No input file specified");
}

BitcoinExchange::BitcoinExchange(std::string filename)
{
	(void) filename;

	// storing the reference data to a map
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw std::runtime_error("File not found");
	std::string line;
	while (std::getline(file, line)) {
		std::istringstream iline(line);
		std::string date, price;
		std::getline(iline, date, '|');
		if (!is_valid_date(date))
			throw std::runtime_error("Invalid date");
		std::getline(iline, price, '|');
		if (!is_valid_price(price))
			throw std::runtime_error("Invalid price");
		_rates[date] = std::stof(price);
	}
	// testing if the map is correctly filled
	for (std::map<std::string, float>::iterator it = _rates.begin(); it != _rates.end(); ++it)
		std::cout << it->first << " " << it->second << std::endl;
}

BitcoinExchange::~BitcoinExchange() {
}