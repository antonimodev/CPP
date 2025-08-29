#include "Cat.hpp"

Cat::Cat(void) {
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat has been created" << std::endl;
}

Cat::Cat(const Cat& other) {
	_type = other._type;
	_brain = new Brain(*other._brain);
	std::cout << "Cat has been copied" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		_type = other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
		std::cout << "Cat has been assigned" << std::endl;
	}
	return *this;
}

Cat::~Cat(void) {
	delete _brain;
	std::cout << "Cat destroyed!" << std::endl;
}

void	Cat::makeSound(void) {
	std::cout << "Meow! Meow!" << std::endl;
}