#include "ScalarConverter.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error: usage: ./scalarconverter <value>" << std::endl;
		return 1;
	}
	(av)++;
	ScalarConverter example;
	example.convert(*av);
	return 0;
}