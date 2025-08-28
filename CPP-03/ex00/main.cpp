#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap 	trap("foo");
	std::string	enemy = "dummy";

	trap.attack(enemy);
	trap.takeDamage(20);
	trap.beRepaired(10);
}