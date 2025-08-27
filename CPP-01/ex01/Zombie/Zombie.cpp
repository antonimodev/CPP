#include "Zombie.hpp"

Zombie::Zombie(void) {
	_name = "NULL";
	std::cout << _name << " zombie has been created." << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << _name << " zombie has been created." << std::endl;
};

Zombie::~Zombie() {
	std::cout << _name << " has been destroyed." << std::endl;
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
