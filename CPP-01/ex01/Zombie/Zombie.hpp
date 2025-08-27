#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
	private:
		std::string _name;

	public:
		Zombie(void);
		Zombie(std::string name); // Builder overcharged
		~Zombie(void);

		void	announce(void);
		void	setName(std::string name);
};

Zombie* zombieHorde(int n, std::string name);

#endif
