#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T> // It allows inheritance from std::stack with any typo (int, unsigned int, etc)
class MutantStack : public std::stack<T> {
	public:
		MutantStack(void);
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack(void);
};

#include "MutantStack.tpp"

#endif