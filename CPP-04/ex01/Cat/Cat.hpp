#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : virtual public Animal {
	private:
		Brain *_brain;

	public:
		Cat(void);
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		virtual ~Cat(void);

		void	makeSound(void);
};

#endif