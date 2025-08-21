#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {};

Zombie::~Zombie() {
	std::cout << _name << " died." << std::endl;
};

void	Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name) {
	_name = name;
}

Zombie* zombieHorde(int n, std::string name) {
	Zombie* horde = new Zombie[n];

	for (int i = 0; i < n; i++)
		horde[i].setName(name);
	return horde;
}
