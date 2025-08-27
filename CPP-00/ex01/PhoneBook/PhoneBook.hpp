#ifndef	PhoneBook_HPP
#define PhoneBook_HPP

#include "Contact.hpp"

/* CLASSES */
class PhoneBook {
	private:
		Contact contacts[8]; // Array of contacts
		size_t	contactCount; // Count
		void	storeContact(const Contact& contact);
	public:
		PhoneBook();
		void	addContact();
		void	searchContact();
		void	printContactsTable(size_t maxContacts) const;
		void	showContactInfo(size_t maxContacts) const;
};

#endif