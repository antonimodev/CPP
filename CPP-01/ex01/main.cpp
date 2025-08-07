#include "Zombie.hpp"

int	main(int ac, char **av) {
	if (ac <= 1) {
		std::cout << "Must be 1 parameter" << std::endl;
		return 1;
	}
	else if (ac > 2) {
		std::cout << "Too many parameters" << std::endl;
	}

	int n = 5; // EXAMPLE
	Zombie* horde = zombieHorde(5, *av);
	
	for (int i = 0; i < n; i++) {
		horde[i].announce();
	}

	delete[] horde;
	return 0;
}