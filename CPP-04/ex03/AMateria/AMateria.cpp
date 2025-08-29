#include "AMateria.hpp"

AMateria::AMateria(const std::string &type) : _type(type) {
	std::cout << _type << " Materia has been created." << std::endl;
}

AMateria::AMateria(const AMateria& other) {
	_type = other._type;

	std::cout << "Materia has been copied!" << std::endl;
}

AMateria&	AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		std::cout << _type << " Materia has been assigned!" << std::endl;
	}
	return *this;

}

AMateria::~AMateria(void) {
	std::cout << _type << " Materia destroyed!." << std::endl;
}

const std::string&	AMateria::getType(void) const {
	return _type;
}

void	AMateria::use(ICharacter& target) {
	if (_type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (_type == "cure")
		std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}