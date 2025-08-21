#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	_type = "Wrong Cat";
	std::cout << "Wrong cat has been created" << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << "Wrong cat has been destroyed" << std::endl;
}

void	WrongCat::makeSound(void) const {
	std::cout << "Wrong cat sound" << std::endl;
}