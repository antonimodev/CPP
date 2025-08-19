#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) 
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {

	_health = 100; // FragTrap
	_energyPoints = 50; // ScavTrap
	_damage = 30; // FragTrap
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap " << _name << " has been destroyed." << std::endl;
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "My name is " << _name << std::endl;
	std::cout << "My ClapTrap name is " << ClapTrap::_name << std::endl;
}