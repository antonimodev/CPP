#include "Bureaucrat.hpp"

int main(void) {
	try {
		Bureaucrat example("antonimo");
		std::cout << example.getName() << " has a grade of " << example.getGrade() << std::endl;
		// example.incrementGrade();
		// example.decrementGrade();
		std::cout << example.getName() << " has a grade of " << example.getGrade() << std::endl;
		std::cout << example << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << "Error" << std::endl;
	}
}