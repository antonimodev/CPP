#include "HumanA.hpp"

static Weapon defaultWeapon("bare hands");

HumanA::HumanA(void) : _name("NULL"), _weapon(defaultWeapon) {}

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA(void) {
	std::cout << _name << " destroyed!." << std::endl;
}

void	HumanA::attack(void) {
	std::cout
			<< _name << " "
			<< "attacks with their "
			<< _weapon.getType() << std::endl;
}