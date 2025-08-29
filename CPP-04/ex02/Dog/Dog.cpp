#include "Dog.hpp"

Dog::Dog(void) : Animal() {
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog has been created" << std::endl;
}

Dog::Dog(const Dog& other) {
	_type = other._type;
	_brain = new Brain(*other._brain);

	std::cout << "Dog has been copied" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		_type = other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
		std::cout << "Dog has been assigned" << std::endl;
	}
	return *this;
}

Dog::~Dog(void) {
	delete _brain;
	std::cout << "Dog destroyed!" << std::endl;
}

void	Dog::makeSound(void) {
	std::cout << "Woof! Woof!" << std::endl;
}