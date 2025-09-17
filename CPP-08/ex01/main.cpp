#include <iostream>

#include "Span.hpp"

int main(void) {
	Span	example(9);

	try {
		example.addNumber(6);
		example.addNumber(3);
		example.addNumber(17);
		example.addNumber(9);
		example.addNumber(11);
		std::cout << "Minor diff: " << example.shortestSpan() << std::endl;
		std::cout << "Major diff: " << example.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}