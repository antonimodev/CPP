#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>

class PmergeMe {
	private:
		std::deque<int>	_bigContainer;
		std::deque<int>	_smallContainer;
		std::deque<int>	_finalContainer;

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe(void);

		// ALGORITHM
		void	splitPairs(std::deque<int>& container);
		void	fordJohnsonSort(void);
		void	binaryInsert(std::deque<int>& src, std::deque<int>& dst);

		// GETTERS
		std::deque<int> getBigContainer(void);
		std::deque<int> getSmallContainer(void);
		std::deque<int> getFinalContainer(void);

		// UTILITIES
		void	print(void);

};

// PARSE
bool    isNumber(const std::string& arg);
bool    isPositive(const std::string& arg);

void	parseArgs(std::deque<int>& container, char **av);
void	deleteDuplicates(std::deque<int>& container);

#endif