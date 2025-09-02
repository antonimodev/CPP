#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat(void);
		WrongCat(const WrongCat& other);
		WrongCat &operator=(const WrongCat& other);
		virtual	~WrongCat(void);

		virtual void	makeSound(void) const;
};

#endif