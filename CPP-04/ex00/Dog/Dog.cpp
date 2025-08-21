#include "Dog.hpp"

Dog::Dog(void) : Animal() {
	_type = "Dog";
	std::cout << "Dog has been created" << std::endl;
}

Dog::~Dog(void) {
	std::cout << "Dog has been destroyed" << std::endl;
}

void	Dog::makeSound(void) {
	std::cout << "Woof! Woof!" << std::endl;
}