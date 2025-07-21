#include "utils.hpp"
#include "Phonebook.hpp"

int	main() {
	size_t		option = 0;
	Phonebook	myNewPhonebook;

	std::cout << "Welcome to your Phonebook!\n";
	while (option != EXIT) {
		display_options();
		option = get_option();
		switch(option) {
			case ADD:
				myNewPhonebook.addContact();
				break;
			case SEARCH:
				myNewPhonebook.searchContact(); // Still in development
				break;
			case EXIT:
				std::cout << "Goodbye!" << std::endl;
				break;
			default:
				error_msg("Invalid option");
				break;
		}
	}
	return 0;
}