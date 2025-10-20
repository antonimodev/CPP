#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
	private:
		static bool	printSpecials(std::string str);
		static bool	printChar(std::string str);
		static bool	printCharQuotes(std::string str);
		static bool	printNoPrintable(std::string str);
		static bool	printNum(std::string str);

	public:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter(void);

	static void convert(std::string str);
};

#endif