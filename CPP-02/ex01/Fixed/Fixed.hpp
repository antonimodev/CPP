#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int 				_fixedPointNumber;
		static const int	_fractionalBits = 8;

	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();

		float				toFloat(void) const;
		int					toInt(void) const;
		friend std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);
};

#endif