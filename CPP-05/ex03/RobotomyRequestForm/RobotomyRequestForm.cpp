#include <ctime>
#include <cstdlib>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("Undefined") {
	std::cout << getName() << " has been created!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << getName() << " has been created!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {
	std::cout << getName() << " has been copied!" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
		std::cout << getName() << " has been assigned!" << std::endl;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << getName() << " has been destroyed!" << std::endl;
}


// Member functions

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (!getIsSigned())
		throw AForm::NotSignedException();

	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::cout << "* Drilling noises *" << std::endl;

	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << _target << "!" << std::endl;
}
