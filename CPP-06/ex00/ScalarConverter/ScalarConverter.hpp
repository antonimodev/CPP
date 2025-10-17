#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

enum Types {
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class ScalarConverter {
	public:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter(void);

	static void convert(std::string str);
};

#endif