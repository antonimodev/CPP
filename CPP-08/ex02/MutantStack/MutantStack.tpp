#include "MutantStack.hpp"

// Initialize with std::stack<T> allows MutantStack to work the same way as the original stack
template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other) {
	if (this != &other)
		std::stack<T>::operator=(other);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack(void) {}

// c is inner container from std::stack, is a protected attribute that allow access to beginning and end as iterators
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
    return this->c.end();
}