#include "Cat.hpp"

Cat::Cat(void) {
	_type = "Cat";
	std::cout << "Cat has been created" << std::endl;
}

Cat::~Cat(void) {
	std::cout << "Cat has been destroyed" << std::endl;
}

void	Cat::makeSound(void) {
	std::cout << "Meow! Meow!" << std::endl;
}