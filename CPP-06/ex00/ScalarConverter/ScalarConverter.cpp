#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <climits>
#include <cerrno>
#include <sstream>

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter(void) {}

bool	printSpecials(const std::string& str) {
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

bool	printChar(const std::string& str) {
	if (!std::isdigit(str[0]) && (str.length() == 1)) {
		std::cout << "Char value is: " << str[0] << std::endl;
		std::cout << "Int value is: " << static_cast<int>(str[0]) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "Float value is: " << static_cast<float>(str[0]) << 'f' << std::endl;
		std::cout << "Double value is " << static_cast<double>(str[0]) << std::endl;
		return true;
	}
	return false;
}

bool	printCharQuotes(const std::string& str) {
	if ((str.length() == 3 && str[0] == '\'' && str[2] == '\'') 
		|| (str.length() == 3 && str[0] == '\"' && str[2] == '\"')) {
		char c = str[1];
		std::cout << "Char value is: " << c << std::endl;
		std::cout << "Int value is: " << static_cast<int>(c) << std::endl;
		std::cout << "Float value is: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "Double value is: " << static_cast<double>(c) << ".0" << std::endl;
		return true;
	}
	return false;
}

bool	printNoPrintable(const std::string& str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isprint(static_cast<unsigned int>(str[i]))) {
			std::cout << "A character is non-printable" << std::endl;
			return true;
		}
	}
	return false;
}

// FIRST VERSION

/* bool	printNum(std::string str) {
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
 */

// SECOND VERSION

/* bool	printNum(const std::string& str) {
    errno = 0;
	// should be nullptr but C++98 doesn't have it
    char *endptr = NULL;

	// endptr points to first position non numeric of the operation std::strtol
    long tempValue = std::strtol(str.c_str(), &endptr, 10);

    if (*endptr != '\0') {
        std::cout << "Error: invalid numeric input" << std::endl;
        return false;
    }

	// ERANGE value is an specific error related to overflow and underflow
	// errno save exit code from the last function in std library
    if (errno == ERANGE || tempValue > INT_MAX || tempValue < INT_MIN) {
        std::cout << "Char value is: impossible" << std::endl;
        std::cout << "Int value is: impossible" << std::endl;
        std::cout << "Float value is: impossible" << std::endl;
        std::cout << "Double value is: impossible" << std::endl;
        return true;
    }

    int intValue = static_cast<int>(tempValue);
    char charValue = static_cast<char>(intValue);
    float floatValue = static_cast<float>(intValue);
    double doubleValue = static_cast<double>(intValue);

    if (charValue < 32 || charValue == 127)
        std::cout << "Char value is: Non printable" << std::endl;
    else
        std::cout << "Char value is: " << charValue << std::endl;

    std::cout << "Int value is: " << intValue << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Float value is: " << floatValue << "f" << std::endl;
    std::cout << "Double value is: " << doubleValue << std::endl;

    return true;
} */

// THIRD VERSION

bool	printNum(const std::string& str) {
	std::istringstream arg(str);
	
	int intValue;
	if (!(arg >> intValue)) {
		std::cout << "Char value is: impossible" << std::endl;
		std::cout << "Int value is: impossible" << std::endl;
		std::cout << "Float value is: impossible" << std::endl;
		std::cout << "Double value is impossible" << std::endl;
		return false;
	}

	if (intValue < 32 || intValue >= 127)
		std::cout << "Char value is: Non displayable" << std::endl;
	else
		std::cout << "Char value is: " << static_cast<char>(intValue) << std::endl;
	std::cout << "Int value is: " << intValue << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "Float value is: " << static_cast<float>(intValue) << "f" << std::endl;
	std::cout << "Double value is: " << static_cast<double>(intValue) << std::endl;
	return true;
}

void	ScalarConverter::convert(const std::string& str) {
	if (printCharQuotes(str))
		return;
	if (printNoPrintable(str))
		return;
	if (printSpecials(str))
		return;
	if (printChar(str))
		return;
	if (printNum(str))
		return;
}