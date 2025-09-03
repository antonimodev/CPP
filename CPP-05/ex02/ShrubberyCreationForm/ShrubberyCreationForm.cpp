#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("Undefined") {
	std::cout << getName() << " has been created!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << getName() << " has been created!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {
	std::cout << getName() << " has been copied!" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
		std::cout << getName() << " has been assigned!" << std::endl;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << getName() << " has been destroyed!" << std::endl;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (!getIsSigned())
		throw AForm::NotSignedException();

	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();

	//Use std::ofstream (library: fstream)
	//To write inside the file created use "<<" heredoc
}
