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