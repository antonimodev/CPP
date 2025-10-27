#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename F>
void    iter(T* array, size_t arrayLength, F function) {
	for (size_t i = 0; i < arrayLength; i++)
		function(array[i]);
};

template <typename T, typename F>
void    iter(const T* array, size_t arrayLength, F function) {
	for (size_t i = 0; i < arrayLength; i++)
		function(array[i]);
};

#endif