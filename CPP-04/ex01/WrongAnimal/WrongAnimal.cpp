#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("None") {
	std::cout << "Wrong Animal of type " << _type << " created!" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type) : _type(type) {
	std::cout << "Wrong Animal of type " << _type << " created!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
	std::cout << "Wrong Animal copy constructor called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other)
		_type = other._type;
	std::cout << "Wrong Animal assignment operator called" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "Wrong Animal of type " << _type << " destroyed!" << std::endl;
}

std::string	WrongAnimal::getType(void) const {
	return _type;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "Wrong Animal of type " << _type << " makes a wrong sound!" << std::endl;
}