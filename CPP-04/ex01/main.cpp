#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void) {
	int	num = 10;
	Animal* animalArray[num];

	for (int i = 0; i < num; i++) {
		if (i < num / 2)
			animalArray[i] = new Cat();
		else
			animalArray[i] = new Dog();
	}

	for (int i = 0; i < num; i++) 
		std::cout << "Animal in array[" << i << "] is a " << animalArray[i]->getType() << std::endl;

	for (int i = 0; i < num; i++) {
		delete animalArray[i];
	}

	return 0;
}