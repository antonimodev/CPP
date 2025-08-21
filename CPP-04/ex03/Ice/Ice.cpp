#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(const Ice& other) : AMateria(other) {
	std::cout << _type << " has been copied" << std::endl;
}

Ice&	Ice::operator=(const Ice& other) {
	if (this != &other) {
		AMateria::operator=(other);
		std::cout << _type << " has been assigned" << std::endl;
	}
	return *this;
}

Ice::~Ice(void) {
	std::cout << _type << " Materia has been destroyed" << std::endl;
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria*	Ice::clone(void) const {
	AMateria *clone = new Ice();
	return clone;
}
