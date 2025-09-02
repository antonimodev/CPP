#include "Form.hpp"
#include "Bureaucrat.hpp" // include bureaucrat.hpp because we use methods of that class

// CONSTRUCTORS

Form::Form(void) : _name("Undefined"), _isSigned(false), _gradeToExecute(20), _gradeToSign(100) {
	std::cout << "Form called " << _name << " has been created!" << std::endl;
}

Form::Form(const std::string name, const unsigned int gradeToSign, const unsigned int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToExecute(gradeToSign), _gradeToSign(gradeToExecute) {
		std::cout << "Form called " << _name << " has been created!" << std::endl;
	}

Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned), _gradeToExecute(other._gradeToSign), _gradeToSign(other._gradeToExecute) {
		std::cout << "Form called " << _name << " has been copied!" << std::endl;
	}

Form&	Form::operator=(const Form& other) {
	if (this != &other) {
		// _name and grades are const and cannot be assigned
		_isSigned = other._isSigned;
		std::cout << "Form called " << _name << " has been assigned!" << std::endl;
	}
	return *this;
}

Form::~Form(void) {
	std::cout << "Form called " << _name << " has been destroyed!" << std::endl;
}

// EXCEPTIONS

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

// MEMBER FUNCTIONS

void				Form::beSigned(const Bureaucrat& bureaucrat) {
	if (_isSigned) {
		std::cout << bureaucrat.getName() << " couldn't sign " << _name << " because is already signed" << std::endl;
		return;
	}
	unsigned int bureaucratGrade = bureaucrat.getGrade();

	if (bureaucratGrade > _gradeToSign) {
		throw GradeTooLowException();
	}

	_isSigned = true;
	std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
}

const std::string&	Form::getName(void) const {
	return _name;
}

bool				Form::getIsSigned(void) const {
	return _isSigned;
}

unsigned int		Form::getGradeToSign(void) const {
	return _gradeToSign;
}

unsigned int		Form::getGradeToExecute(void) const {
	return _gradeToExecute;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName() << ", signed: " << (form.getIsSigned() ? "yes" : "no") 
		<< ", grade to sign: " << form.getGradeToSign() 
		<< ", grade to execute: " << form.getGradeToExecute();
    return os;
}