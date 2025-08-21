#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("Wrong None") {
	std::cout << "Wrong Animal has been created" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "Wrong Animal has been destroyed" << std::endl;
}

std::string	WrongAnimal::getType(void) const {
	return _type;
}

void	WrongAnimal::makeSound(void) {
	std::cout << "Wrong sound!" << std::endl;
}