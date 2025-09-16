#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>

template <typename T>
class Array {
	private:
		unsigned int	_size;
		T*				_array;

	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array& other);
		Array&		operator=(const Array& other);
		T&			operator[](unsigned int index);
		const T&	operator[](unsigned int index) const;
		~Array(void);

		unsigned int	size(void) const;
};

#include "Array.tpp"

#endif