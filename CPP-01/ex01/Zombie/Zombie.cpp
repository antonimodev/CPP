#include "Zombie.hpp"

Zombie::Zombie(void) : _name("NULL") {}

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << _name << " zombie has been created." << std::endl;
};

Zombie::~Zombie() {
	std::cout << _name << " destroyed!" << std::endl;
};

void	Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name) {
	_name = name;
}