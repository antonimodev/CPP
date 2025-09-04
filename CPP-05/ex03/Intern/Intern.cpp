#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void) {
	std::cout << "Intern has been created" << std::endl;
}

Intern::Intern(const Intern& other) {
	(void) other; // Prevent errors/warnings while compiling. Indicates an ignored operation
	std::cout << "Intern has been copied!" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
	(void) other;
	std::cout << "Intern has been assigned!" << std::endl;
	return *this;
}

Intern::~Intern(void) {
	std::cout << "Intern has been destroyed" << std::endl;
}


// MEMBER FUNCTIONS
AForm*  Intern::createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm*  Intern::createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm*  Intern::createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string formName, const std::string formTarget) {
	std::string formNames[3] = {
		"presidential pardon",
		"robotomy request", 
		"shrubbery creation"
	};

	AForm* (Intern::*formCreators[3])(const std::string&) = {
		&Intern::createPresidentialPardonForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createShrubberyCreationForm
	};

	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*formCreators[i])(formTarget);
		}
	}

	std::cout << "Error: Form name '" << formName << "' does not exist!" << std::endl;
	return NULL;
}

// If we have func like this:
// AForm*  Intern::createRobotomyRequestForm(const std::string& target)
// It means that syntax would be something like this:
// AForm* (Intern::*)(const std::string&);
// Return, pointer to func, parameter of that func.
// func must be: &Intern::createRobotomyRequestForm for example.