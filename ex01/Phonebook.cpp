#include "utils.hpp"
#include "Phonebook.hpp"

Phonebook::Phonebook() : contactCount(0) {}

void	Phonebook::storeContact(const Contact& contact) {
	contacts[contactCount % 8] = contact; // contactCount % 8 -> circular array
	contactCount++;
	std::cout << "Contact added successfully!" << std::endl;
}

void	Phonebook::addContact() {
	Contact		newContact;
	std::string	user_input;

	std::cout << "Enter first name: " << std::flush;
	while (user_input.empty()) {
		std::cout << "First name cannot be empty" << std::endl;
		std::getline(std::cin, user_input);
	}
	newContact.setFirstName(user_input);

	std::cout << "Enter last name: " << std::flush;
	while (user_input.empty()) {
		std::cout << "Last name cannot be empty" << std::endl;
		std::getline(std::cin, user_input);
	}
	newContact.setLastName(user_input);

	std::cout << "Enter nickname: " << std::flush;
	while (user_input.empty()) {
		std::cout << "Nickname cannot be empty" << std::endl;
		std::getline(std::cin, user_input);
	}
	newContact.setNickname(user_input);

	std::cout << "Enter phone number: " << std::flush;
	while (user_input.empty()) {
		std::cout << "Phone number cannot be empty" << std::endl;
		std::getline(std::cin, user_input);
	}
	newContact.setPhoneNumber(user_input);

	std::cout << "Enter darkest secret: " << std::flush;
	while (user_input.empty()) {
		std::cout << "Darkest secret cannot be empty" << std::endl;
		std::getline(std::cin, user_input);
	}
	newContact.setDarkestSecret(user_input);

	// Adding this contact to array
	storeContact(newContact);
}
