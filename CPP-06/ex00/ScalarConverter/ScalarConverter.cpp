#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cctype>
#include <iomanip>

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter(void) {}

bool	ScalarConverter::printSpecials(std::string str) {
	std::string exceptions[] = {"nan", "nanf", "-inf", "-inff", "+inf", "+inff"};
	size_t exceptionsCount = sizeof(exceptions) / sizeof(exceptions[0]);

	for (size_t i = 0; i < exceptionsCount; ++i) {
		if (str == exceptions[i]) {
			std::cout << "Char value is: impossible" << std::endl;
			std::cout << "Int value is: impossible" << std::endl;
			std::cout << "Float value is: " << str << "f" << std::endl;
			std::cout << "Double value is: " << str << std::endl;
			return true;
		}
	}
	return false;
}

bool	ScalarConverter::printChar(std::string str) {
	if (!std::isdigit(str[0]) && (str.length() == 1)) {
		std::cout << "Char value is: " << str[0] << std::endl;
		std::cout << "Int value is: " << static_cast<int>(str[0]) << std::endl;
		std::cout << "Float value is: " << std::fixed << std::setprecision(1) << static_cast<float>(str[0]) << 'f' << std::endl;
		std::cout << "Double value is " << std::fixed << std::setprecision(1) << static_cast<double>(str[0]) << std::endl;
		return true;
	}
	return false;
}

bool	ScalarConverter::printCharQuotes(std::string str) {
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'') {
		char c = str[1];
		std::cout << "Char value is:  '" << c << "'" << std::endl;
		std::cout << "Int value is: " << static_cast<int>(c) << std::endl;
		std::cout << "Float value is: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "Double value is: " << static_cast<double>(c) << ".0" << std::endl;
		return true;
	}
	return false;
}

bool	ScalarConverter::printNoPrintable(std::string str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isprint(static_cast<unsigned int>(str[i]))) {
			std::cout << "A character is non-printable" << std::endl;
			return true;
		}
	}
	return false;
}

bool	ScalarConverter::printNum(std::string str) {
	int intValue = atoi(str.c_str());
	float floatValue = atof(str.c_str());
	double doubleValue = static_cast<double>(floatValue);
	char charValue = static_cast<char>(intValue);
	
	if (charValue < 32 || charValue == 127)
		std::cout << "Char value is: Non printable" << std::endl;
	else
		std::cout << "Char value is: " << charValue << std::endl;
	std::cout << "Int value is: " << intValue << std::endl;
	std::cout << "Float value is: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
	std::cout << "Double value is: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
	return true;
}

void ScalarConverter::convert(std::string str) {
	ScalarConverter converter;

	if (converter.printCharQuotes(str))
		return;
	if (converter.printNoPrintable(str))
		return;
	if (converter.printSpecials(str))
		return;
	if (converter.printChar(str))
		return;
	if (converter.printNum(str))
		return;
}