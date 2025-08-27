#ifndef HUMANB_H
#define HUMANB_H

#include <iostream>
#include "Weapon.hpp"

class HumanB {
	private:
		std::string	_name;
		Weapon*		_weapon;

	public:
		HumanB(void);
		HumanB(std::string name);
		~HumanB(void);

		void	setWeapon(Weapon& weapon);
		void	attack(void);
};

#endif