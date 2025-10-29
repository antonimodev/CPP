#pragma once

#include <iostream>
#include <deque>
#include <vector>

class PmergeMe {
	private:
		std::deque<int>	_bigDequeContainer;
		std::deque<int>	_smallDequeContainer;
		std::deque<int>	_finalDequeContainer;

		std::vector<int>	_bigVectorContainer;
		std::vector<int>	_smallVectorContainer;
		std::vector<int>	_finalVectorContainer;

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe(void);

		// DEQUE
		void	splitPairs(const std::deque<int>& container, std::deque<int>& smallContainer,
				std::deque<int>& bigContainer);
		void	fordJohnsonSort(std::deque<int>& input);
		void	binaryInsert(std::deque<int>& src, std::deque<int>& dst);

		// VECTOR
		void	splitPairs(const std::vector<int>& container, std::vector<int>& smallContainer,
				std::vector<int>& bigContainer);
		void	fordJohnsonSort(std::vector<int>& input);
		void	binaryInsert(std::vector<int>& src, std::vector<int>& dst);

		// UTILITIES
		void	print(void);
};

// PARSE
bool    isNumber(const std::string& arg);
bool    isPositive(const std::string& arg);

// DEQUE
void	parseArgs(std::deque<int>& container, char **av);
void	deleteDuplicates(std::deque<int>& container);

// VECTOR
void	parseArgs(std::vector<int>& container, char **av);
void	deleteDuplicates(std::vector<int>& container);