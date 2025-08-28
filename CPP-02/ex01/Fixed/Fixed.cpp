#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointNumber(0) {}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	_fixedPointNumber = other._fixedPointNumber;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	_fixedPointNumber = other._fixedPointNumber;
	return *this;
}

Fixed::Fixed(const int num) {
	_fixedPointNumber = num << _fractionalBits;
}

Fixed::Fixed(const float num) {
	_fixedPointNumber = static_cast<int>(num * (1 << _fractionalBits));
}

Fixed::~Fixed(void) {};

float	Fixed::toFloat(void) const {
	return static_cast<float>(_fixedPointNumber) / (1 << _fractionalBits);
}

int	Fixed::toInt(void) const {
	return _fixedPointNumber >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}
