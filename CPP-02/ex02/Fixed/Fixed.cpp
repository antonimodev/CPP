#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointNumber(0) {}

Fixed::Fixed(const int value) {
	_fixedPointNumber = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	_fixedPointNumber = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) : _fixedPointNumber(other._fixedPointNumber) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& other) {
	if (this !=& other) {
		_fixedPointNumber = other._fixedPointNumber;
	}
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

// Comparative operators

bool	Fixed::operator>(const Fixed& other) const {
	return (_fixedPointNumber > other._fixedPointNumber);
}

bool	Fixed::operator<(const Fixed& other) const {
	return (_fixedPointNumber < other._fixedPointNumber);
}

bool	Fixed::operator>=(const Fixed& other) const {
	return (_fixedPointNumber >= other._fixedPointNumber);
}

bool	Fixed::operator<=(const Fixed& other) const {
	return (_fixedPointNumber <= other._fixedPointNumber);
}

bool	Fixed::operator!=(const Fixed& other) const {
	return (_fixedPointNumber != other._fixedPointNumber);
}

bool	Fixed::operator==(const Fixed& other) const {
	return (_fixedPointNumber == other._fixedPointNumber);
}

// Arithmetic operators

Fixed	Fixed::operator+(const Fixed& other) const {
	return Fixed(_fixedPointNumber + other._fixedPointNumber);
}

Fixed	Fixed::operator-(const Fixed& other) const {
	return Fixed(_fixedPointNumber - other._fixedPointNumber);
}

// It fails if I return directly like other functions
Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;
	result._fixedPointNumber = (_fixedPointNumber * other._fixedPointNumber) / (1 << _fractionalBits);
	return result;
}

Fixed	Fixed::operator/(const Fixed& other) const {
	return Fixed(static_cast<float>(_fixedPointNumber) / other._fixedPointNumber);
}

// Increment/Decrement operators

Fixed	&Fixed::operator++(void) {
	_fixedPointNumber++;
	return *this;
}

Fixed	&Fixed::operator--(void) {
	_fixedPointNumber--;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed result;
	result._fixedPointNumber = _fixedPointNumber;
	_fixedPointNumber++;
	return result;
}

Fixed	Fixed::operator--(int) {
	Fixed result;
	result._fixedPointNumber = _fixedPointNumber;
	_fixedPointNumber--;
	return result;
}

// Min/Max

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a._fixedPointNumber < b._fixedPointNumber) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a._fixedPointNumber > b._fixedPointNumber) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a._fixedPointNumber < b._fixedPointNumber) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a._fixedPointNumber > b._fixedPointNumber) ? a : b;
}

std::ostream &operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}

float	Fixed::toFloat(void) const {
	return (static_cast<float>(_fixedPointNumber) / (1 << _fractionalBits));
}

int	Fixed::toInt(void) const {
	return (_fixedPointNumber >> _fractionalBits);
}