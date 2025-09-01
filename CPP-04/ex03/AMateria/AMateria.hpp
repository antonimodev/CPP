#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

#include "Character.hpp"
#include "ICharacter.hpp"

class AMateria {
	protected:
		std::string	_type;

	public:
		AMateria(void);
		AMateria(const std::string &type);
		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& other);
		virtual ~AMateria(void);

		const std::string&	getType(void) const;

		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter& target);
};

#endif