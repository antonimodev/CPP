#include "HumanB.hpp"

HumanB::HumanB(void) : _name("NULL"), _weapon(NULL) {}

HumanB::HumanB(std::string name) : _name(name) {}

HumanB::~HumanB(void) {
	std::cout << _name << " destroyed!" << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}

void	HumanB::attack(void) {
	if (_weapon) {
		std::cout
				<< _name << " "
				<< "attacks with their "
				<< _weapon->getType() << std::endl;
	}
	else
		std::cout << "Cannot attack" << std::endl;
}
