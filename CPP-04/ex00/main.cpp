#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void) {
	std::cout << "=== ANIMAL POLYMORPHISM ===" << std::endl;
	const Animal*	base = new Animal();
	const Animal* 	dog = new Dog();
	const Animal* 	cat = new Cat();

	std::cout << "\nTypes:" << std::endl;
	std::cout << base->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	std::cout << "\nSounds:" << std::endl;
	base->makeSound();
	dog->makeSound();
	cat->makeSound();

	std::cout << "\n=== WRONG ANIMAL POLYMORPHISM ===" << std::endl;
	const WrongAnimal*	wrongBase = new WrongAnimal();
	const WrongCat*		wrongCat = new WrongCat();

	std::cout << "\nTypes:" << std::endl;
	std::cout << wrongBase->getType() << std::endl;
	std::cout << wrongCat->getType() << std::endl;

	std::cout << "\nSounds:" << std::endl;
	wrongBase->makeSound();
	wrongCat->makeSound();

	std::cout << "\n=== DESTRUCTION ===" << std::endl;
	delete base;
	delete dog;
	delete cat;
	delete wrongBase;
	delete wrongCat;

	return 0;
}