#include "Array.hpp"
#include <iostream>

int	main(void) {
	Array<int>	example(10);
	example[2] = 23;
	
	try {
		for (size_t i = 0; i < 15; i++)
			std::cout << example[i] << std::endl;
	} catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
};