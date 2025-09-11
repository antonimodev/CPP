#include "ScalarConverter.hpp"
#include <cstdlib>
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

void ScalarConverter::convert(std::string str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isprint(static_cast<unsigned int>(str[i]))) {
			std::cout << "A character is non-printable" << std::endl;
			return;
		}
	}
	std::string exceptions[] = {"nan", "nanf", "-inf", "-inff", "+inf", "+inff"};
	size_t exceptionsCount = sizeof(exceptions) / sizeof(exceptions[0]);
	for (size_t i = 0; i < exceptionsCount; i++) {
		if (str == exceptions[i]) {
			std::cout << "You can't use the following args: nan/nanf/-inf/-inff/+inf/+inff" << std::endl;
			return;
		}
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