#include <iostream>

int	main(void) {
	std::string foo = "HI THIS IS BRAIN"; // STRING ITSELF
	std::string& stringREF = foo; // STRING REF
	std::string* stringPTR = &foo; // MEM ADDR

	std::cout << "The memory address of the string variable: " << &foo << std::endl;
	std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "The value of the string variable: " << foo << std::endl;
	std::cout << "The value pointed to by stringPTR: " << stringREF << std::endl;
	std::cout << "The value pointed to by stringREF: " << *stringPTR << std::endl;
}