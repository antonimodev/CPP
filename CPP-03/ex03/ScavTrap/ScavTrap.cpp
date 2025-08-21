#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_health = 100;
	_energyPoints = 50;
	_damage = 20;

	std::cout << "ScavTrap " << _name << " constructed!" << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << _name << " destroyed!" << std::endl;
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}