#include <iostream>

#include "Iter.hpp"

void	printChar(char chr) {
	std::cout << chr << std::endl;
}

void	capitalizeChar(char &chr) {
	if (std::isalpha(chr))
		chr = std::toupper(chr);
}

int main(void) {
	std::string	myString = "Hello world!";
	iter(&myString[0], myString.size(), printChar);
	iter(&myString[0], myString.size(), capitalizeChar);
	iter(&myString[0], myString.size(), printChar);
	return 0;
}