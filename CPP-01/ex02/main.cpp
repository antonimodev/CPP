#include <iostream>

int	main(void) {
	std::string foo = "HI THIS IS BRAIN"; // STRING ITSELF
	std::string& stringRef = foo; // STRING REF
	std::string* stringPtr = &foo; // MEM ADDR

	std::cout
		<< foo << "\n"
		<< stringRef << "\n"
		<< stringPtr << std::endl;
}