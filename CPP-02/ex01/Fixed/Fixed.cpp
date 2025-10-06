#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointNumber(0) {}

Fixed::Fixed(const int num) {
	_fixedPointNumber = num << _fractionalBits;
}

Fixed::Fixed(const float num) {
	_fixedPointNumber = static_cast<int>(num * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) : _fixedPointNumber(other._fixedPointNumber) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& other) {
	_fixedPointNumber = other._fixedPointNumber;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Fixed::~Fixed(void) {};

// operation to fixedpointnumbers with 8 fractionalbits, is equivalent to num * 2^8
float	Fixed::toFloat(void) const {
	return static_cast<float>(_fixedPointNumber) / (1 << _fractionalBits);
}

int	Fixed::toInt(void) const {
	return _fixedPointNumber / (1 << _fractionalBits);
	//return _fixedPointNumber >> fractionalBits; This is more idiomatic form in C++
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}
