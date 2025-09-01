#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "iostream"

class Bureaucrat {
	private:
		const std::string   _name;
		unsigned int        _grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat(void);

		const std::string&	getName(void) const;
		unsigned int		getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);

		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what(void) const throw() {
					return "Exception: Grade is too high!";
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what(void) const throw() {
					return "Exception: Grade is too low!";
				}
		};
	};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif