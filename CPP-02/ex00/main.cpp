#include "Fixed.hpp"

int	main(void) {
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	std::cout << std::endl;
	std::cout <<  a.getRawBits() << "\n" << std::endl;
	std::cout <<  b.getRawBits() << "\n" << std::endl;
	std::cout <<  c.getRawBits() << "\n" << std::endl;

	return 0;
}