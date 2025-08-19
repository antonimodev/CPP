#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_health = 100;
	_energyPoints = 100;
	_damage = 30;

	std::cout << "FragTrap " << _name << " has been created!" << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << _name << " has been destroyed!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}