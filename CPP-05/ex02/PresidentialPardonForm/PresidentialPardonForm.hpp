#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
// Required grades: sign 25, exec 5
class PresidentialPardonForm : public AForm {
	private:
		std::string	_target;

	public:
	// CONSTRUCTORS
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm(void);

	// MEMBER FUNCTIONS
		void	execute(const Bureaucrat& executor) const;
};

#endif