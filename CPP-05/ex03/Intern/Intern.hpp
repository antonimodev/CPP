#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
	public:
		Intern(void);
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern(void);

		AForm*	createPresidentialPardonForm(const std::string& target);
		AForm*	createRobotomyRequestForm(const std::string& target);
		AForm*	createShrubberyCreationForm(const std::string& target);
		AForm*	makeForm(const std::string formName, const std::string formTarget);
};

#endif