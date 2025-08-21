#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void) {
	const Animal*	base = new Animal();
	const Animal* 	dog = new Dog();
	const Animal* 	cat = new Cat();
	const WrongAnimal*	wrongBase = new WrongAnimal();
	const WrongCat*		wrongCat = new WrongCat();

	std::cout << base->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	base->makeSound();
	dog->makeSound();
	cat->makeSound();

	std::cout << wrongBase->getType() << std::endl;
	std::cout << wrongCat->getType() << std::endl;

	wrongBase->makeSound();
	wrongCat->makeSound();

	delete base;
	delete dog;
	delete cat;
	delete wrongBase;
	delete wrongCat;

	return 0;
}