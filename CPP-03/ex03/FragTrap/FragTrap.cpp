#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("undefined") {}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_health = 100;
	_energyPoints = 100;
	_damage = 30;

	std::cout << "FragTrap " << _name << " has been created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "Copy constructor called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &other) {
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << _name << " destroyed!!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " requests a positive high five!" << std::endl;
}