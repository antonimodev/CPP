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
		if (std::cin.fail() || option < 1 || option > 3) {
			std::cin.clear(); // Clear error flag
			std::cin.ignore(999, '\n'); // Big number to ignore chars in buffer after fail
			error_msg("Invalid input. Please enter 1, 2 or 3");
			continue;
		}
		if (option == ADD || option == SEARCH || option == EXIT)
			break;
		std::cout << "Invalid option. Please enter 1, 2, or 3" << std::endl;
	}
	return (option);
}

std::string	get_user_input(std::string msg) {
	std::string user_input;
	
	std::cout << msg << std::flush;
	while (user_input.empty()) {
		std::cout << "Input cannot be empty." << std::endl;
		std::getline(std::cin, user_input);
	}
	return (user_input);
}

std::string formatField(const std::string& str) {
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

void	error_msg(const std::string error_msg) {
	std::cout << "Error" << std::endl;
	std::cout << error_msg << std::endl;
}
