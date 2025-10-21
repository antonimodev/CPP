#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter(void);

	public:
		static void convert(const std::string& str);
};

bool	printChar(const std::string& str);
bool	printCharQuotes(const std::string& str);
bool	printNum(const std::string& str);
bool	printSpecials(const std::string& str);
bool	printNoPrintable(const std::string& str);

#endif