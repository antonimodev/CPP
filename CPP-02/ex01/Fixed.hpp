#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int					_fixedPointNumber;
		static const int	_fractionalBits = 8;

	public:
		Fixed(const int num);
		Fixed(const float num);
		Fixed(void);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		float	toFloat(void) const;
		int		toInt(void)	const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif