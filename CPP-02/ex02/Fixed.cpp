#include "Fixed.hpp"

Fixed::Fixed(void) {}

Fixed::Fixed(const float) {}

Fixed::Fixed(const int) {}

Fixed::~Fixed(void) {}

// Comparative operators

bool	Fixed::operator>(const Fixed &other) const {
	return this->_fixedPointNumber > other._fixedPointNumber;
}

bool	Fixed::operator<(const Fixed &other) const {
	return this->_fixedPointNumber < other._fixedPointNumber;
}

bool	Fixed::operator>=(const Fixed &other) const {
	return this->_fixedPointNumber >= other._fixedPointNumber;
}

bool	Fixed::operator<=(const Fixed &other) const {
	return this->_fixedPointNumber <= other._fixedPointNumber;
}

bool	Fixed::operator!=(const Fixed &other) const {
	return this->_fixedPointNumber != other._fixedPointNumber;
}

bool	Fixed::operator==(const Fixed &other) const {
	return this->_fixedPointNumber == other._fixedPointNumber;
}

// Arithmetic operators

Fixed	Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result._fixedPointNumber = this->_fixedPointNumber + other._fixedPointNumber;
	return result;
}

Fixed	Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result._fixedPointNumber = this->_fixedPointNumber - other._fixedPointNumber;
	return result;
}

Fixed	Fixed::operator*(const Fixed &other) const {
	Fixed result;
	result._fixedPointNumber = this->_fixedPointNumber * other._fixedPointNumber;
	return result;
}

Fixed	Fixed::operator/(const Fixed &other) const {
	Fixed result;
	result._fixedPointNumber = this->_fixedPointNumber / other._fixedPointNumber;
	return result;
}

// Increment/Decrement operators

Fixed	&Fixed::operator--(void) {
	this->_fixedPointNumber--;
	return *this;
}

Fixed	&Fixed::operator++(void) {
	this->_fixedPointNumber++;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed result;
	result._fixedPointNumber = this->_fixedPointNumber--;
	return result;
}

Fixed	Fixed::operator++(int) {
	Fixed result;
	result._fixedPointNumber = this->_fixedPointNumber++;
	return result;
}

// 

Fixed& Fixed::min(Fixed &a, Fixed &b) {
	if (a._fixedPointNumber < b._fixedPointNumber)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
	if (a._fixedPointNumber > b._fixedPointNumber)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
	if (a._fixedPointNumber < b._fixedPointNumber)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
	if (a._fixedPointNumber > b._fixedPointNumber)
		return a;
	return b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

float	Fixed::toFloat(void) const {
	return static_cast<float>(_fixedPointNumber) / (1 << _fractionalBits);
}

int	Fixed::toInt(void) const {
	return _fixedPointNumber >> _fractionalBits;
}