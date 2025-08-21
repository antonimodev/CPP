#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
	protected:
		std::string _type;

	public:
		Animal(void);
		virtual ~Animal(void);

		virtual std::string getType(void) const;
		virtual void makeSound(void) const = 0; // Animal class becomes abstract by this method
};

#endif