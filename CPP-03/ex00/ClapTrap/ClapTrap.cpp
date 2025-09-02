#include "ClapTrap.hpp"

// In C++11 we cant use ClapTrap::ClapTrap(void) : ClapTrap("undefined") to call another
// constructor in the member initializer list

ClapTrap::ClapTrap(void) : _name("undefined"), _health(10), _energyPoints(10), _damage(0) {
	std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _health(10), _energyPoints(10), _damage(0) {
	std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _health(other._health), _energyPoints(other._energyPoints), _damage(other._damage) {
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this !=& other) {
		_name = other._name;
		_health = other._health;
		_energyPoints = other._energyPoints;
		_damage = other._damage;
	}
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << _name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (target.empty()) {
		std::cout << _name << " cannot attack an empty target!" << std::endl;
		return;
	}

	if (_energyPoints < 1) {
		std::cout << _name << " does not have enough energy points to attack." << std::endl;
		return;
	}

	_energyPoints--;
	std::cout << _name << " attacks " << target << " causing " << _damage << " points of damage." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_health == 0) {
		std::cout << _name << " is already dead and cannot take more damage." << std::endl;
		return;
	}

	_health = (_health > amount) ? (_health - amount) : 0;
	std::cout << _name << " has been attacked and lost " << amount << " health points." << std::endl;

	if (_health == 0)
		std::cout << _name << " has died." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints < 1) {
		std::cout << _name << " does not have enough energy points to repair." << std::endl;
		return;
	}

	if (_health <= 0) {
		std::cout << _name << " is death, cannot be repaired." << std::endl;
		return;
	}

	_health = (_health + amount <= 10) ? _health + amount : 10;
	_energyPoints--;
	std::cout << _name << " restored " << amount << " of health." << std::endl;
}