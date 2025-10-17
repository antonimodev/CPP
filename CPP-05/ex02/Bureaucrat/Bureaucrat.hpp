#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class AForm;

class Bureaucrat {
	private:
		const std::string   _name;
		unsigned int		_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, const unsigned int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat &operator=(const Bureaucrat& other);
		~Bureaucrat(void);

		const std::string&	getName(void) const;
		unsigned int		getGrade(void) const;
		void				setGrade(unsigned int grade);
		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(AForm& aform) const;
		void				executeForm(const AForm& form) const;

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif