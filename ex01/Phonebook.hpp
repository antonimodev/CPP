#ifndef	PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

/* CLASSES */
class Phonebook {
	private:
		Contact contacts[8]; // Array of contacts
		size_t	contactCount; // Count
		void	storeContact(const Contact& contact);
	public:
		Phonebook();
		void	addContact();
		void	searchContact();
};

#endif