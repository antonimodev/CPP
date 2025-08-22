#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		std::string	_name;
		AMateria	*_ISlots[4];

	public:
		Character(std::string name);
		Character(const Character& other);
		Character& operator=(const Character& other);
		~Character(void);

		std::string const& getName() const override;
		void equip(AMateria* m) override;
		void unequip(int idx) override;
		void use(int idx, ICharacter& target) override;
};

#endif