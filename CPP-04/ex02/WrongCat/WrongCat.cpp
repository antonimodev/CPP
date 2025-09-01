#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("Cat") {
	std::cout << "Wrong Animal of type " << _type << " created!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << "Wrong Cat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other)
		WrongAnimal::operator=(other);
	std::cout << "Wrong Cat assignment operator called" << std::endl;
	return *this;
}

WrongCat::~WrongCat(void) {
	std::cout << "Wrong Animal of type " << _type << " destroyed!" << std::endl;
}

void	WrongCat::makeSound(void) const {
	std::cout << "Wrong Animal of type " << _type << " says: Meoawueaw!" << std::endl;
}