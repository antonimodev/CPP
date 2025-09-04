#include "AForm.hpp"
#include "Bureaucrat.hpp" // include bureaucrat.hpp because we use methods of that class

// CONSTRUCTORS

AForm::AForm(void) : _name("Undefined"), _isSigned(false), _gradeToSign(100), _gradeToExecute(20) {
	std::cout << "AForm called " << _name << " has been created!" << std::endl;
}

AForm::AForm(const std::string name, const unsigned int gradeToSign, const unsigned int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
		std::cout << "AForm called " << _name << " has been created!" << std::endl;
	}

AForm::AForm(const AForm& other)
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
		std::cout << "AForm called " << _name << " has been copied!" << std::endl;
	}

// _name and grades are const and cannot be assigned
AForm&	AForm::operator=(const AForm& other) {
	if (this != &other) {
		_isSigned = other._isSigned;
		std::cout << "AForm called " << _name << " has been assigned!" << std::endl;
	}
	return *this;
}

AForm::~AForm(void) {
	std::cout << "AForm called " << _name << " has been destroyed!" << std::endl;
}

// MEMBER FUNCTIONS

void				AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (_isSigned) {
		std::cout << bureaucrat.getName() << " couldn't sign " << _name << " because is already signed" << std::endl;
		return;
	}
	unsigned int bureaucratGrade = bureaucrat.getGrade();

	if (bureaucratGrade > _gradeToSign)
		throw GradeTooLowException();

	_isSigned = true;
	std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
}

const std::string&	AForm::getName(void) const {
	return _name;
}

bool				AForm::getIsSigned(void) const {
	return _isSigned;
}

unsigned int		AForm::getGradeToSign(void) const {
	return _gradeToSign;
}

unsigned int		AForm::getGradeToExecute(void) const {
	return _gradeToExecute;
}

// EXCEPTIONS

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

const char* AForm::NotSignedException::what(void) const throw() {
	return "Form is not signed!";
}

// If it's true, getIsSigned returns yes, otherwise no
std::ostream& operator<<(std::ostream& os, const AForm& AForm) {
    os << "AForm " << AForm.getName() << ", signed: " << (AForm.getIsSigned() ? "yes" : "no") 
		<< ", grade to sign: " << AForm.getGradeToSign() 
		<< ", grade to execute: " << AForm.getGradeToExecute();
    return os;
}