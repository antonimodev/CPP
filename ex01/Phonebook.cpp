#include "utils.hpp"
#include "Phonebook.hpp"

Phonebook::Phonebook() {
	contactCount = 0;
}

void	Phonebook::storeContact(const Contact& contact) {
	contacts[contactCount % 8] = contact; // contactCount % 8 -> circular array
	contactCount++;
	std::cout << "Contact added successfully!" << std::endl;
}

void	Phonebook::addContact() {
	Contact		newContact;
/* 	std::string	user_input;

	std::cout << "Enter first name: " << std::flush;
	while (user_input.empty()) {
		std::cout << "First name cannot be empty" << std::endl;
		std::getline(std::cin, user_input);
	} */
	newContact.setFirstName(get_user_input("Enter first name: "));

/* 	std::cout << "Enter last name: " << std::flush;
	while (user_input.empty()) {
		std::cout << "Last name cannot be empty" << std::endl;
		std::getline(std::cin, user_input);
	} */
	newContact.setLastName(get_user_input("Enter last name: "));

/* 	std::cout << "Enter nickname: " << std::flush;
	while (user_input.empty()) {
		std::cout << "Nickname cannot be empty" << std::endl;
		std::getline(std::cin, user_input);
	} */
	newContact.setNickname(get_user_input("Enter nickname: "));

/* 	std::cout << "Enter phone number: " << std::flush;
	while (user_input.empty()) {
		std::cout << "Phone number cannot be empty" << std::endl;
		std::getline(std::cin, user_input);
	} */
	newContact.setPhoneNumber(get_user_input("Enter phone number: "));

/* 	std::cout << "Enter darkest secret: " << std::flush;
	while (user_input.empty()) {
		std::cout << "Darkest secret cannot be empty" << std::endl;
		std::getline(std::cin, user_input);
	} */
	newContact.setDarkestSecret(get_user_input("Enter darkest secret: "));

	// Adding this contact to array
	storeContact(newContact);
}

void	Phonebook::printContactsTable(size_t maxContacts) const {
	size_t	i;

	std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|   Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
	i = 0;
	while (i < maxContacts) {
        std::cout << "|" << std::setw(8) << i + 1 << "|"
			<< std::setw(10) << formatField(contacts[i].getFirstName()) << "|"
            << std::setw(10) << formatField(contacts[i].getLastName()) << "|"
            << std::setw(10) << formatField(contacts[i].getNickname()) << "|" << std::endl;
			i++;
    }
    std::cout << "---------------------------------------------" << std::endl;
}

void	Phonebook::showContactInfo(size_t maxContacts) const {
	size_t			index;
	Contact			selectedContact;

	index = 0;
	std::cout << "Enter the index of the contact to display: " << std::flush;
	std::cin >> index;
	if (std::cin.fail() || index < 1 || index > maxContacts) {
		std::cin.clear();
		std::cin.ignore(999, '\n');
		std::cout << "Invalid index." << std::endl;
		return;
	}
	selectedContact = contacts[index - 1];
	std::cout << "First Name: " << selectedContact.getFirstName() << std::endl;
	std::cout << "Last Name: " << selectedContact.getLastName() << std::endl;
	std::cout << "Nickname: " << selectedContact.getNickname() << std::endl;
	std::cout << "Phone Number: " << selectedContact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << selectedContact.getDarkestSecret() << std::endl;
}

void	Phonebook::searchContact() {
	size_t	maxContacts;

	if (contactCount < 8)
		maxContacts = contactCount;
	else
		maxContacts = 8;
	printContactsTable(maxContacts);
	showContactInfo(maxContacts);
}
