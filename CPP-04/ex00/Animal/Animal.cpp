#include "Animal.hpp"

Animal::Animal(void) : _type("None") {
	std::cout << "Animal has been generated" << std::endl;
}

Animal::~Animal(void) {
	std::cout << "Animal has been destroyed" << std::endl;
}

void	Animal::makeSound(void) {
	std::cout << "Generic sound" << std::endl;
}

std::string	Animal::getType(void) {
	return _type;
}