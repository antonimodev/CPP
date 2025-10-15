#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat; // Forward Declaration because I only use pointers (*) or references (&) in this class

class Form {
	private:
		const std::string		_name;
		bool					_isSigned;
		const unsigned int		_gradeToExecute;
		const unsigned int		_gradeToSign;

	public:
		//constructors
		Form(void);
		Form(const std::string name, const unsigned int gradeToSign, const unsigned int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form(void);

		void				beSigned(const Bureaucrat& bureaucrat);
		const std::string&	getName(void) const;
		bool				getIsSigned(void) const;
		unsigned int		getGradeToSign(void) const;
		unsigned int		getGradeToExecute(void) const;

		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				const char* what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif