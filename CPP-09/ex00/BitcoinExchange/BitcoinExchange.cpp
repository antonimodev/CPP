#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>


BitcoinExchange::BitcoinExchange(const std::string db_filename) {
	std::ifstream db(db_filename.c_str());
	if (!db.is_open()) {
		std::cerr << "Error: could not open database file: " << db_filename << std::endl;
		return;
	}
	_db = load_db(db);
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _db(other._db) {}


BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		_db = other._db;
	return *this;
}


BitcoinExchange::~BitcoinExchange(void) {}


// ------------------- Private -------------------

std::map<std::string, double>	BitcoinExchange::load_db(std::ifstream& db) {
	std::map<std::string, double> db_map;
	std::string line;

	std::getline(db, line);
	while (std::getline(db, line)) {
		size_t pos = line.find(',');
		if (pos == std::string::npos)
			continue;

		std::string date = line.substr(0, pos);
		std::string rate_str = line.substr(pos + 1);
		double rate = 0;
		if (store_safe_stod(rate_str, rate))
			db_map[date] = rate;
	}
	return db_map;
}


bool	BitcoinExchange::store_safe_stod(const std::string& str, double& value) {
	std::stringstream numberStream(str);
	numberStream >> value;
	if (numberStream.fail() || !numberStream.eof() || value > 1000)
		return false;
	return true;
}


bool	BitcoinExchange::validate_date(const std::string& date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009 || year > 2025)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1)
		return false;

	int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		days_in_month[1] = 29;
	if (day > days_in_month[month - 1])
		return false;
	return true;
}


// ------------------- Public -------------------

void BitcoinExchange::process_input_file(const std::string& filename) {
	std::ifstream input(filename.c_str());
	if (!input.is_open()) {
		std::cerr << "Error: could not open file: " << filename << std::endl;
		return;
	}

	std::string line;
	while (line.empty())
		if (!std::getline(input, line)) {
			std::cerr << "Error: file is empty" << std::endl;
			exit(1);
		}

	while (std::getline(input, line)) {
		if (line.empty())
			continue;
		size_t pos = line.find('|');
		if (pos == std::string::npos) {
			std::cerr << "Error: | separator missing => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, pos));
		if (!validate_date(date)) {
			std::cerr << "Error: invalid date => " << date << std::endl;
			continue;
		}

		double value = 0;
		if (!store_safe_stod(line.substr(pos + 1), value)) {
			std::cerr << "Error: invalid value => " << line.substr(pos + 1) << std::endl;
			continue;
		}

		std::map<std::string,double>::iterator it = _db.find(date);
		if (it == _db.end()) {
			it = _db.lower_bound(date);
			if (it == _db.begin()) {
				std::cerr << "Error: no earlier date available => " << date << std::endl;
				continue;
			}
			--it;
		}

		double result = value * it->second;
		if (result < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (result > 1e+10) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		std::cout << date << " => " << value << " = " << result << std::endl;
	}
}


// ------------- General ------------------ 


void	validExtension(char **av) {
	std::string input = av[1];
	size_t pos = input.rfind('.');
	std::string extension = input.substr(pos + 1);

	if (extension != "txt") {
		std::cerr << "Error: file format must be .txt" << std::endl;
		exit(1);
	}
}


std::string	trim(const std::string& str) {
	size_t first = str.find_first_not_of(" \t");

	if (first == std::string::npos)
		return "";

	size_t last = str.find_last_not_of(" \t");
	return str.substr(first, (last - first) + 1);
}