#include "Utils.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	contactCount = 0;
}

void	PhoneBook::storeContact(const Contact& contact) {
	contacts[contactCount % 8] = contact; // contactCount % 8 -> circular array
	contactCount++;
	std::cout << "Contact added successfully!" << std::endl;
}

void	PhoneBook::addContact() {
	Contact		newContact;
	newContact.setFirstName(get_user_input("Enter first name: "));
	newContact.setLastName(get_user_input("Enter last name: "));
	newContact.setNickname(get_user_input("Enter nickname: "));
	newContact.setPhoneNumber(get_user_input("Enter phone number: "));
	newContact.setDarkestSecret(get_user_input("Enter darkest secret: "));
	storeContact(newContact);
}

void	PhoneBook::printContactsTable(size_t maxContacts) const {
	size_t	i;

	std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|   Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
	i = 0;
	while (i < maxContacts) {
        std::cout << "|" << std::setw(8) << i + 1 << "|"
			<< std::setw(10) << format_field(contacts[i].getFirstName()) << "|"
            << std::setw(10) << format_field(contacts[i].getLastName()) << "|"
            << std::setw(10) << format_field(contacts[i].getNickname()) << "|" << std::endl;
			i++;
    }
    std::cout << "---------------------------------------------" << std::endl;
}

void	PhoneBook::showContactInfo(size_t maxContacts) const {
	size_t			index;
	Contact			selectedContact;

	index = 0;
	std::cout << "Enter the index of the contact to display: " << std::flush;
	std::cin >> index;
	handle_eof();
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

void	PhoneBook::searchContact() {
	size_t	maxContacts;

	if (contactCount < 8)
		maxContacts = contactCount;
	else
		maxContacts = 8;
	printContactsTable(maxContacts);
	showContactInfo(maxContacts);
}
