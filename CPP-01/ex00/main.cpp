#include "Zombie.hpp"

int	main(void) {
	// Stack in this scope
	Zombie zombie("pedro");
	zombie.announce();

	// Stack, in the scope of randomChump
	randomChump("pedrito");

	// Heap, pointer to use var in any scope
	Zombie* secondZombie = newZombie("pedrazo");
	secondZombie->announce();
	// Must be delete because is dynamic memory
	delete secondZombie;

	return;
}