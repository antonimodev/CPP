#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void) {
	try {
		AForm exam("Examen", 20, 20);
		Bureaucrat example("antonimo", 15);
		example.signAForm(exam);
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << "Bureaucrat Error: " << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << "Bureaucrat Error: " << e.what() << std::endl;
	} catch (const AForm::GradeTooHighException& e) {
		std::cout << "Form Error: " << e.what() << std::endl;
	} catch (const AForm::GradeTooLowException& e) {
		std::cout << "Form Error: " << e.what() << std::endl;
	}

	return 0;
}