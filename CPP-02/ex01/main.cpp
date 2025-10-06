#include "Fixed.hpp"
#include <iostream>

int main(void) {
	Fixed		a;
	Fixed const	b(10);
	Fixed const	c(42.42f);

	// Copy constructor
	Fixed const	d(b);
	// Assignment constructor
	a = Fixed(1234.4321f);

	std::cout << "\nOverload of '<<' operator" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "\ntoFloat()" << std::endl;
	std::cout << "a as float: " << a.toFloat() << std::endl;
	std::cout << "b as float: " << b.toFloat() << std::endl;
	std::cout << "c as float: " << c.toFloat() << std::endl;
	std::cout << "d as float: " << d.toFloat() << std::endl;

	std::cout << "\ntoInt()" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}