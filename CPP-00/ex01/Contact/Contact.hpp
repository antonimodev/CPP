#ifndef CONTACT_HPP
#define CONTACT_HPP

/* INCLUDES */
#include "Utils.hpp"

/* CLASSES */
class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		// SETTERS
		void	setFirstName(const std::string& name);
		void	setLastName(const std::string& name);
		void	setNickname(const std::string& name);
		void	setPhoneNumber(const std::string& number);
		void	setDarkestSecret(const std::string& secret);
		// GETTERS
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickname(void) const;
		std::string	getPhoneNumber(void) const;
		std::string	getDarkestSecret(void) const;
	};

#endif