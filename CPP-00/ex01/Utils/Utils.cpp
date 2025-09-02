#include "Utils.hpp"

void	handle_eof(void) {
	if (std::cin.eof()) {
		std::cout << "\nEOF detected, exiting..." << std::endl;
		exit(0);
	}
}

void	display_options(void) {
	std::cout << "Select an option:" << std::endl;
	std::cout << "1. ADD CONTACT" << std::endl;
	std::cout << "2. SEARCH CONTACT" << std::endl;
	std::cout << "3. EXIT" << std::endl;
}

static std::string	strtrim(std::string& str) {
	const std::string	whitespaces = " \t\n\r\f\v";

	std::string::size_type start = str.find_first_not_of(whitespaces);
	if (start == std::string::npos)
		return "";
	std::string::size_type end = str.find_last_not_of(whitespaces);
	return str.substr(start, end - start + 1);
}

/* size_t	get_option(void) {
	size_t	option = 0;

	while (true) {
		std::cout << "Enter an option: " << std::flush;
		std::cin >> option;
		handle_eof();
		if (std::cin.fail() || option < 1 || option > 3) {
			std::cin.clear(); // Clear error flag
			std::cin.ignore(999, '\n'); // Big number to ignore chars in buffer after fail
			error_msg("Invalid input. Please enter 1, 2 or 3");
			continue;
		}
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.ignore(999, '\n');
		if (option == ADD || option == SEARCH || option == EXIT)
			break;
		std::cout << "Invalid option. Please enter 1, 2, or 3" << std::endl;
	}
	return (option);
} */

size_t	get_option(void) {
    size_t		option = 0;
    std::string	line;

    while (true) {
        std::cout << "Enter an option: " << std::flush;
        std::getline(std::cin, line);
        handle_eof();
        line = strtrim(line);
        if (line.empty()) {
            error_msg("Invalid input. Please enter 1, 2 or 3");
            continue;
        }
        if (line.length() != 1 || !std::isdigit(line[0])) {
            error_msg("Invalid input. Please enter 1, 2 or 3");
            continue;
        }
        option = line[0] - '0';
        if (option < 1 || option > 3) {
            error_msg("Invalid input. Please enter 1, 2 or 3");
            continue;
        }
        break;
    }
    return (option);
}

std::string	get_user_input(std::string msg) {
	std::string user_input;
	while (true) {
		std::cout << msg << std::flush;
		std::getline(std::cin, user_input);
		handle_eof();
		if (user_input.empty()) {
			std::cout << "Input cannot be empty." << std::endl;
			continue;
		}
		break;
	}
	return (user_input);
}

std::string format_field(const std::string& str) {
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

void	error_msg(const std::string error_msg) {
	std::cout << "Error" << std::endl;
	std::cout << error_msg << std::endl;
}
