#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	std::cout << "Animal of type " << _type << " created!" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog& other) {
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Dog assignment operator called" << std::endl;
	return *this;
}

Dog::~Dog(void) {
	std::cout << "Animal of type " << _type << " destroyed!" << std::endl;
}

void	Dog::makeSound(void) const {
	std::cout << "Animal of type " << _type << " says: Woof! Woof!" << std::endl;
}