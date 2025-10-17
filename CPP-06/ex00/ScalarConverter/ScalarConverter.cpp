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

/* Types	whichType(char *str) {

} */

void ScalarConverter::convert(std::string str) {
	// char between "'c'"
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'') {
		char c = str[1];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
		return;
	}
	// non-printable
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isprint(static_cast<unsigned int>(str[i]))) {
			std::cout << "A character is non-printable" << std::endl;
			return;
		}
	}
	// nan/nanf, inf/inff -inf/-inff
	std::string exceptions[] = {"nan", "nanf", "-inf", "-inff", "+inf", "+inff"};
	size_t exceptionsCount = sizeof(exceptions) / sizeof(exceptions[0]);

	for (size_t i = 0; i < exceptionsCount; ++i) {
		if (str == exceptions[i]) {
			std::cout << "You can't use the following args: nan/nanf/-inf/-inff/+inf/+inff" << std::endl;
			return;
		}
	}
	// characters
	if (!std::isdigit(str[0])) {
		std::cout << "Int value is: " << static_cast<int>(str[0]) << std::endl;
		std::cout << "Float value is: " << std::fixed << std::setprecision(1) << static_cast<float>(str[0]) << 'f' << std::endl;
		std::cout << "Double value is " << std::fixed << std::setprecision(1) << static_cast<double>(str[0]) << std::endl;
		std::cout << "Char value is: " << str[0] << std::endl;
		return;
	}

	int intValue = atoi(str.c_str());
	float floatValue = atof(str.c_str());
	double doubleValue = static_cast<double>(floatValue);
	char charValue = static_cast<char>(intValue);
	
	std::cout << "Int value is: " << intValue << std::endl;
	std::cout << "Float value is: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
	std::cout << "Double value is: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
	if (charValue < 32 || charValue == 127)
		std::cout << "Char value is: Non printable" << std::endl;
	else
		std::cout << "Char value is: " << charValue << std::endl;
}