#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string   _name;
		bool                _isSigned;
		const unsigned int  _gradeToSign;
		const unsigned int  _gradeToExecute;
	public:
		//constructors
		Form(void);
		Form(const std::string _name, const unsigned int gradeToSign, const unsigned int gradeToExecute);
		Form(const Form& other);
		Form &operator=(const Form& other);
		~Form(void);

		void	signForm(const Bureaucrat& bureaucrat);
		const std::string &getName(void) const;
		bool getIsSigned(void) const;
		bool getGradeToSign(void) const;
		bool getGradeToExecute(void) const;

		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what(void) const throw() {
					return "!";
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what(void) const throw() {
					return "!";
				}
		};
};

#endif