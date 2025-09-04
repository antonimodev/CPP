#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"


// CONSTRUCTORS


PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("Undefined") {
	std::cout << getName() << " has been created!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << getName() << " has been created!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target) {
	std::cout << getName() << " has been copied!" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
		std::cout << getName() << " has been assigned!" << std::endl;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << getName() << " has been destroyed!" << std::endl;
}


// MEMBER FUNCTIONS


void	PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (!getIsSigned())
		throw AForm::NotSignedException();

	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::cout << _target << " has been pardoned by Zaphod Beeblerox" << std::endl;
}
