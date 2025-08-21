#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>

#include "AMateria.hpp"

// If we don't need initialize any parameter, we can build classes without builders
class ICharacter {
	public:
		virtual ~ICharacter() {}
		virtual std::string const& getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;

		
};

#endif