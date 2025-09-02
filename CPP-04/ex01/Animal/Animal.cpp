#include "Animal.hpp"

Animal::Animal(void) : _type("None") {
	std::cout << "Animal of type " << _type << " created!" << std::endl;
}

Animal::Animal(const std::string &type) : _type(type) {
	std::cout << "Animal of type " << _type << " created!" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal& other) {
	if (this !=& other)
		_type = other._type;
	std::cout << "Animal assignment operator called" << std::endl;
	return *this;
}

Animal::~Animal(void) {
	std::cout << "Animal of type " << _type << " destroyed!" << std::endl;
}

void	Animal::makeSound(void) const {
	std::cout << "Animal of type " << _type << " makes a generic sound!" << std::endl;
}

std::string	Animal::getType(void) const {
	return _type;
}