#include "Weapon.hpp"

Weapon::Weapon(void) : _type("NULL") {}

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::~Weapon(void) {
	if (_type != "bare hands")
		std::cout << "Weapon type: " << _type << " has been destroyed." << std::endl;
}

const std::string&	Weapon::getType(void) const {
	return _type;
};

void	Weapon::setType(std::string type) {
	_type = type;
};
