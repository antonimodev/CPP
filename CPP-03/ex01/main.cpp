#include "ScavTrap.hpp"

int main(void) {
	ScavTrap	scav("MC");
	std::string enemy = "Enemy";

	scav.attack(enemy);
	scav.takeDamage(10);
	scav.guardGate();
	scav.beRepaired(10);
}