#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void) {
	try {
		//Instance AForm -> Presidential/Robotomy/Shrubbery
		Bureaucrat example("antonimo", 15);
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