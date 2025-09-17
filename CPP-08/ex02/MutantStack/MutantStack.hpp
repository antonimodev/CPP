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

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator begin(void);
		iterator end(void);
		const_iterator begin(void) const;
		const_iterator end(void) const;
};

#include "MutantStack.tpp"

#endif