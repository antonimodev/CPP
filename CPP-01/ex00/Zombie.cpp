#include "Zombie.hpp"

void	Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie*	newZombie(std::string name) {
	return new Zombie(name);
}

void	randomChump(std::string name) {
	Zombie zombie(name);
	zombie.announce();
}