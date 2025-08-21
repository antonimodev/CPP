#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void) {
	int	num = 10;
	Animal* animalArray[num];

	for (int i = 0; i < num; i++) {
		if (i < num / 2)
			animalArray[i] = new Cat();
		else
			animalArray[i] = new Dog();
	}

	for (int i = 0; i < num; i++) {
		delete animalArray[i];
	}

	return 0;
}