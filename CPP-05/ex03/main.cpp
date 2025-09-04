#include <ctime>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
	try {
		srand(std::time(0)); // Robotomy needs random seed to randomize 50%
		PresidentialPardonForm	presidential;
		RobotomyRequestForm		robotomy;
		ShrubberyCreationForm	shrubbery;

		Bureaucrat example("antonimo", 5);
		std::cout << std::endl;

		presidential.beSigned(example);
		robotomy.beSigned(example);
		shrubbery.beSigned(example);
		std::cout << std::endl;

		presidential.execute(example);
		std::cout << std::endl;
		robotomy.execute(example);
		std::cout << std::endl;
		shrubbery.execute(example);

	} catch (const AForm::NotSignedException& e) {
		std::cout << "AForm Error: " << e.what() << std::endl;
		return 1;
	} catch (const AForm::GradeTooHighException& e) {
		std::cout << "AForm Error: " << e.what() << std::endl;
		return 1;
	} catch (const AForm::GradeTooLowException& e) {
		std::cout << "AForm Error: " << e.what() << std::endl;
		return 1;
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << "Bureaucrat Error: " << e.what() << std::endl;
		return 1;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << "Bureaucrat Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}