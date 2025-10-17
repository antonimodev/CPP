#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	try {
		Form exam("Examen", 20, 20);
		Bureaucrat example("antonimo");
		example.setGrade(15);
		example.signForm(exam);
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << "Bureaucrat Error: " << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << "Bureaucrat Error: " << e.what() << std::endl;
	} catch (const Form::GradeTooHighException& e) {
		std::cout << "Form Error: " << e.what() << std::endl;
	} catch (const Form::GradeTooLowException& e) {
		std::cout << "Form Error: " << e.what() << std::endl;
	}

	return 0;
}