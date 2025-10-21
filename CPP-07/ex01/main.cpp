#include <iostream>
#include <vector>

#include "Iter.hpp"

void	printChar(const char& chr) {
	std::cout << chr << std::endl;
}

void	capitalizeChar(char& chr) {
	if (std::isalpha(chr))
		chr = std::toupper(chr);
}

int main(void) {
	std::string	myString = "Hello world!";
	iter(&myString[0], myString.size(), printChar);
	iter(&myString[0], myString.size(), capitalizeChar);
	iter(&myString[0], myString.size(), printChar);

	std::cout << std::endl;

	std::vector<char> test;
	test.push_back('a');
	test.push_back('b');
	// .data() returns pointer to first element inside
	iter(test.data(), test.size(), printChar);

	return 0;
}