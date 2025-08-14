#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int					_fixedPointNumber;
		static const int	_fractionalBits = 8;

	public:
		// Standard builder
		Fixed(void);
		// Copy builder
		Fixed(const Fixed &other);
		// Operator assignment
		Fixed &operator=(const Fixed &other);
		// Destructor
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif