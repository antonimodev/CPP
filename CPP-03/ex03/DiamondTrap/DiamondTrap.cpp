#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("undefined_clap_name"), ScavTrap("undefined"), FragTrap("undefined"), _name("undefined") {
    _health = 100; // FragTrap
    _energyPoints = 50; // ScavTrap
    _damage = 30; // FragTrap
    std::cout << "DiamondTrap " << _name << " has been created!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
	_health = 100; // FragTrap
	_energyPoints = 50; // ScavTrap
	_damage = 30; // FragTrap
	std::cout << "DiamondTrap " << _name << " has been created!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this !=& other) {
		ClapTrap::operator=(other);
		_name = other._name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap " << _name << " destroyed!" << std::endl;
}

void DiamondTrap::whoAmI(void) {
	std::cout << "My name is " << _name << std::endl;
	std::cout << "My ClapTrap name is " << ClapTrap::_name << std::endl;
}