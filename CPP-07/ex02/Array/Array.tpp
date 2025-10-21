#include <stdexcept>
#include "Array.hpp"

// CONCEPT: Create _array with new T[_size](), initialize automatically each element to 0, use () at the end.

template <typename T>
Array<T>::Array(void) : _size(0), _array(new T[0]()) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _array(new T[_size]()) {}

template <typename T>
Array<T>::Array(const Array& other) : _size(other._size), _array(new T[_size]()) {
	for (size_t i = 0; i < _size; ++i)
		_array[i] = other._array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
		delete[] _array; // Clear current array to store a new one
		_size = other._size;
		_array = new T[_size];
	for (size_t i = 0; i < _size; ++i)
		_array[i] = other._array[i];
	}
	return *this;
}

// NO CONST
template <typename T>
T&	Array<T>::operator[](unsigned int index) {
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return _array[index];
}

// CONST
template <typename T>
const T&	Array<T>::operator[](unsigned int index) const {
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return _array[index];
}

template <typename T>
Array<T>::~Array(void) {
	delete[] _array;
}

template <typename T>
unsigned int	Array<T>::size(void) const {
	return _size;
}