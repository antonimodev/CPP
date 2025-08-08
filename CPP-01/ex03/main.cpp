// STILL IN DEVELOPMENT
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int	main(void) {
	Weapon	club("crude spiked club");

	HumanA	bob("Bob", club);
	bob.attack();
	club.setType("Some other type of club");
	bob.attack();

	HumanB	jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("crude spiked club again");
	jim.attack();

	return 0;
}
