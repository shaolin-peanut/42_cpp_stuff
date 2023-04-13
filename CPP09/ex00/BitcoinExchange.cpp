//
// Created by Samuel Bars on 4/13/23.
//

#include "BitcoinExchange.hpp"

static bool is_valid_date(const std::string& date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') { // check the length and separators
		return false;
	}
	int year, month, day;
	std::istringstream ss(date);
	char dash;
	if (!(ss >> year >> dash >> month >> dash >> day)) { // try to extract year, month, and day
		return false;
	}
	if (year < 1900 || year > 9999 || month < 1 || month > 12 || day < 1) { // check the range of year, month, and day
		return false;
	}
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // array to hold the number of days in each month
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) { // check if the year is a leap year
		daysInMonth[1] = 29; // set February to have 29 days in a leap year
	}
	if (day > daysInMonth[month - 1]) { // check if the day is valid for the given month
		return false;
	}

	return true;
}

bool is_valid_historical_price(const std::string& price)
{
	if ((price == "price") || (price == "value")) { // skip the header line
		return true;
	}

	if (price == "0" || price == "0.0" || price == "0.00") {
		return true; }

	double price_value = atof(price.c_str());

	if (price_value > 0) {
		return true; }
	else {
		return false; }
}


bool is_valid_price(const std::string& price)
{
	if (price == "price") { // skip the header line
		return true;
	}
	double nPrice = atof(price.c_str()); // convert the string to a double using atof
	if (nPrice >= 0 && nPrice <= 1000) { // check if the price is within the valid range
		return true;
	}
	return false;
}


BitcoinExchange::BitcoinExchange()
{
	if (!parse_database("data.csv")) {
		throw std::runtime_error("Error parsing the database");
	}
}


BitcoinExchange::~BitcoinExchange() {
}

bool BitcoinExchange::parse_database(std::string filename)
{
	// storing the reference data to a map
	// testing if the map is correctly filled
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		return false;

	std::string line;
	// Parcourir les lignes du fichier
	while (std::getline(file, line)) {
		std::istringstream iline(line);
		std::string date, price;

		// Extraire la date et vérifier sa validité
		std::getline(iline, date, ',');
		if (date == "date") { // skip the header line
			continue; } // go to the next line
		if (!is_valid_date(date)) {
			std::cerr << "parse: Date invalide : " << date << std::endl;
			continue;
		}

		// Extraire le prix et vérifier sa validité
		std::getline(iline, price, ',');
		if (!is_valid_historical_price(price)) {
			std::cerr << "parse: Prix invalide : " << price << std::endl;
			continue;
		}

		// Convertir le prix en float et l'ajouter à la map _rates
		std::istringstream price_stream(price);
		float price_value;
		price_stream >> price_value;
		//_rates.insert(std::make_pair(date, price_value));
		_rates[date] = price_value;
		return (true);
	}
	return true;
}
std::string	BitcoinExchange::closest_date_value(std::string& date)
{
	std::string closest_date = "";

	std::map<std::string, float>::iterator it = _rates.find(date);
	if (it == _rates.end())
	{
		std::map<std::string, float>::iterator it2 = _rates.begin();
		while (it2 != _rates.end())
		{
			const std::string& current_date = it2->first;
			if (current_date <= date && current_date > closest_date)
				closest_date = current_date;
			it2++;
		}
		return (closest_date);
	}
	return (it->first);
}

bool BitcoinExchange::convert(std::string filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		return false;

	std::string line;
	while (std::getline(file, line)) {
		if (line.substr(0, 4) == "date") {
			continue;  // Skip the header line
		}

		std::istringstream iline(line);
		std::string date, value;

		// check validity of date and price
		std::getline(iline, date, '|');
		if (!is_valid_date(date)) {
			std::cerr << "convert: Date invalide : " << date << std::endl;
			continue; }
		std::getline(iline, value, '|');
		if (!is_valid_price(value)) {
			std::cerr << "convert: Prix invalide : " << value << std::endl;
			continue; }

		// convert price and value to float
		float fprice = _rates[closest_date_value(date)];
		float fvalue = atof(value.c_str());
		// print the result
		std::cout << date << "|" << value << "|" << fprice * fvalue << std::endl;
	}
	return true;
}