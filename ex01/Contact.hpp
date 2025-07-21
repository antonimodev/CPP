#ifndef CONTACT_HPP
#define CONTACT_HPP

/* INCLUDES */
#include "utils.hpp"

/* CLASSES */
class	Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		void	setFirstName(const std::string name);
		void	setLastName(const std::string name);
		void	setNickname(const std::string name);
		void	setPhoneNumber(const std::string number);
		void	setDarkestSecret(const std::string secret);
};

#endif