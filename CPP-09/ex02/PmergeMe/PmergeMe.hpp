#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>

class PmergeMe {
	private:

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe(void);

		void	fordJohnsonSort(std::deque<int>& container);
};

bool    isNumber(const std::string& arg);
bool    isPositive(const std::string& arg);

#endif