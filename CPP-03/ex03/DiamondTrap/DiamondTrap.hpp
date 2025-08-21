#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string _name;

	public:
		DiamondTrap(std::string name);
		~DiamondTrap(void);

		using ScavTrap::attack;

		void whoAmI(void);
};

#endif