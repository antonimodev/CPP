#include "Fixed.hpp"

int	main(void) {
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << "\nInitial value of a (float): " << a << std::endl;
	std::cout << "Initial value of a (int): " << a.toInt() << std::endl;

	std::cout << "\nPre-increment (++a): " << ++a << std::endl;
	std::cout << "Value of a after pre-increment (float): " << a << std::endl;
	std::cout << "Value of a after pre-increment (int): " << a.toInt() << std::endl;

	std::cout << "\nPost-increment (a++): " << a++ << std::endl;
	std::cout << "Value of a after post-increment (float): " << a << std::endl;
	std::cout << "Value of a after post-increment (int): " << a.toInt() << std::endl;

	std::cout << "\nValue of b (result of 5.05f * 2, float): " << b << std::endl;
	std::cout << "Value of b (int): " << b.toInt() << std::endl;

	std::cout << "\nMaximum between a and b (float): " << Fixed::max(a, b) << std::endl;
	std::cout << "Maximum between a and b (int): " << Fixed::max(a, b).toInt() << std::endl;

	return 0;
}