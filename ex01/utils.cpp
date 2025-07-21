#include "utils.hpp"

void	display_options(void) {
	std::cout << "Select an option:" << std::endl;
	std::cout << "1. ADD CONTACT" << std::endl;
	std::cout << "2. SEARCH CONTACT" << std::endl;
	std::cout << "3. EXIT" << std::endl;
}

size_t	get_option(void) {
	size_t	option = 0;

	while (true) {
		std::cout << "Enter an option: " << std::flush;
		std::cin >> option;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(999, '\n'); // Big number to ignore chars in buffer after fail
			error_msg("Invalid input. Please enter 1, 2 or 3");
			continue;
		}
		if (option == ADD || option == SEARCH || option == EXIT)
			break;
		std::cout << "Invalid option. Please enter 1, 2, or 3" << std::endl;
	}
	return option;
}

void	error_msg(const std::string error_msg) {
	std::cout << "Error" << std::endl;
	std::cout << error_msg << std::endl;
}