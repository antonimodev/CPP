#include "Bureaucrat.hpp"
#include "AForm.hpp"

// CONSTRUCTORS

Bureaucrat::Bureaucrat(void) : _name("Undefined"), _grade(150) {
	std::cout << "Bureaucrat named " << _name << " has been created!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const unsigned int grade) : _name(name), _grade(grade) {
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat named " << _name << " has been created!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

// Can't assign members if they're const, _name is const
Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		_grade = other._grade;
		std::cout << "Bureaucrat assignment operator called" << std::endl;
	}
	return *this;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat " << _name << " has been destroyed!" << std::endl;
}

// MEMBER FUNCTIONS

void	Bureaucrat::signForm(AForm& form) const {
	form.beSigned(*this);
}

const std::string&	Bureaucrat::getName(void) const {
	return _name;
}

unsigned int		Bureaucrat::getGrade(void) const {
	return _grade;
}

void				Bureaucrat::executeForm(const AForm& form) const {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << _name << " couldn't execute " << form.getName()
		<< " because " << e.what() << std::endl;
	}
}

// Grade cannot be greater than 150 or less than 1
// Increments goes towards 1 and decrements goes towards 150
void				Bureaucrat::incrementGrade(void) {
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void				Bureaucrat::decrementGrade(void) {
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

// EXCEPTIONS

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Exception: Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Exception: Grade is too low!";
}

//

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade: " << bureaucrat.getGrade();
	return os;
}