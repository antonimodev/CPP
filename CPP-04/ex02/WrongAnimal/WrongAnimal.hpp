#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	protected:
		std::string	_type;

	public:
		WrongAnimal(void);
		virtual	~WrongAnimal(void);

		virtual std::string getType(void) const;
		void	makeSound(void) const;
};

#endif
