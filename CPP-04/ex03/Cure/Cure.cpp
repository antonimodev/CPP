#include "Cure.hpp"

Cure::Cure(void) : AMateria("Cure") {}

Cure::Cure(const Cure& other) : AMateria(other) {
	std::cout << _type << " has been copied" << std::endl;
}

Cure&	Cure::operator=(const Cure& other) {
	if (this != &other) {
		AMateria::operator=(other);
		std::cout << _type << " has been assigned" << std::endl;
	}
	return *this;
}

Cure::~Cure(void) {
	std::cout << _type << " Materia has been destroyed" << std::endl;
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria*	Cure::clone(void) const {
	AMateria *clone = new Cure();
	return clone;
}
