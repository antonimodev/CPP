#include "Animal.hpp"

Animal::Animal(void) : _type("None") {
	std::cout << "Animal has been generated" << std::endl;
}

Animal::~Animal(void) {
	std::cout << "Animal destroyed!" << std::endl;
}

void	Animal::makeSound(void) const {
	std::cout << "Generic sound" << std::endl;
}

std::string	Animal::getType(void) const {
	return _type;
}