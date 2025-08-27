#include "Utils.hpp"
#include "PhoneBook.hpp"

int	main() {
	size_t		option = 0;
	PhoneBook	myNewPhoneBook;

	std::cout << "Welcome to your PhoneBook!\n";
	while (option != EXIT) {
		display_options();
		option = get_option();
		switch (option) {
			case ADD:
				myNewPhoneBook.addContact();
				break;
			case SEARCH:
				myNewPhoneBook.searchContact();
				break;
			case EXIT:
				std::cout << "Goodbye!" << std::endl;
				break;
			default:
				error_msg("Invalid option");
		}
	}
	return 0;
}