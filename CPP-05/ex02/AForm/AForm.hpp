#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>

class Bureaucrat; // Forward Declaration because I only use pointers (*) or references (&) in this class

class AForm {
	private:
		const std::string		_name;
		bool					_isSigned;
		const unsigned int		_gradeToExecute;
		const unsigned int		_gradeToSign;

	public:
		//constructors
		AForm(void);
		AForm(const std::string name, const unsigned int gradeToSign, const unsigned int gradeToExecute);
		AForm(const AForm& other);
		AForm &operator=(const AForm& other);
		~AForm(void);

		void				beSigned(const Bureaucrat& bureaucrat);
		const std::string&	getName(void) const;
		bool				getIsSigned(void) const;
		unsigned int		getGradeToSign(void) const;
		unsigned int		getGradeToExecute(void) const;
		virtual void		execute(const Bureaucrat& executor) const = 0; // This class becomes abstract

		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				const char* what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what(void) const throw();
		};
		class NotSignedException : std::exception {
			public:
				const char* what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif