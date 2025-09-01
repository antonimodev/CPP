#include <iostream>

#include "Character.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main(void) {
	Character* hero = new Character("Hero");
	Character* villain = new Character("Villain");

	AMateria* ice = new Ice();
	AMateria* cure = new Cure();

	hero->equip(ice);
	hero->equip(cure);

	hero->use(0, *villain);
	hero->use(1, *villain);

	delete hero;
	delete villain;

	return 0;
}