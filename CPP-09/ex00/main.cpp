#include <iostream>
#include <fstream>
#include <map>

//#include "BitcoinExchange.hpp"


std::map<std::string, double>	load_db(std::ifstream& db) {
	std::map<std::string, double> db_map;
	std::string line;

	std::getline(db, line);
	while (std::getline(db, line)) {
		size_t pos = line.find(',');
		if (pos == std::string::npos) {
			std::cout << "Invalid line: " << line << std::endl;
			continue;
		}
		try {
			db_map[line.substr(0, pos)] = std::stod(line.substr(pos + 1));
		} catch (const std::exception& e) {
			std::cout << "Invalid number in line: " << line << " (" << e.what() << ")" << std::endl;
			continue;
		}
	}
	return db_map;
}

//pending of test
void	process_input_file(std::map<std::string, double> db_map, std::ifstream& input) {
	std::string line;
	std::getline(input, line);
	while (std::getline(input, line)) {
		size_t pos = line.find("|");
		if (pos == std::string::npos) {
			std::cout << "whatever msg" << std::endl;
			continue;
		}
		std::string date = line.substr(0, pos);
		double value = std::stod(line.substr(pos + 1));
		std::map<std::string, double>::iterator it = db_map.find(date);
		if (it != db_map.end()) {
			double result = value * it->second;
			std::cout << date << " => " << value << " = " << result << std::endl;
		} else
			std::cout << "Date not found: " << date << std::endl;
	}
}

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: usage: ./btc <input.txt>" << std::endl;
		return 1;
	}
	std::ifstream db("data.csv");
	if (!db.is_open()) {
		std::cerr << "Error: introduce 'data.csv' from subject to load initial database" << std::endl;
		return 1;
	}
	std::ifstream input(av[1]);
	if (!input.is_open()) {
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}

	std::map<std::string, double> db_map = load_db(db); // data.csv loaded in map
	//process_input_file(db_map, input);
	return 0;
}