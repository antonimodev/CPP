#include "PmergeMe.hpp"
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <set>
#include <stdexcept>

// constructors still in development, (void) to avoid make errors
PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe& other) :
	_bigDequeContainer(other._bigDequeContainer),
	_smallDequeContainer(other._smallDequeContainer),
	_finalDequeContainer(other._bigDequeContainer),
	_bigVectorContainer(other._bigVectorContainer),
	_smallVectorContainer(other._smallVectorContainer),
	_finalVectorContainer(other._finalVectorContainer) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _bigDequeContainer = other._bigDequeContainer;
        _smallDequeContainer = other._smallDequeContainer;
        _finalDequeContainer = other._finalDequeContainer;
        _bigVectorContainer = other._bigVectorContainer;
        _smallVectorContainer = other._smallVectorContainer;
        _finalVectorContainer = other._finalVectorContainer;
    }
    return *this;
}

PmergeMe::~PmergeMe(void) {}


// DEQUE

void	PmergeMe::splitPairs(const std::deque<int>& container, std::deque<int>& smallContainer,
	std::deque<int>& bigContainer)
{
	for (size_t i = 0; i + 1 < container.size(); i += 2) {
		if (container[i] < container[i + 1]) {
			smallContainer.push_back(container[i]);
			bigContainer.push_back(container[i + 1]);
		} else {
			smallContainer.push_back(container[i + 1]);
			bigContainer.push_back(container[i]);
		}
	}
	if (container.size() % 2 != 0)
		smallContainer.push_back(container.back());
}

void	PmergeMe::fordJohnsonSort(std::deque<int>& container) {
	if (container.size() <= 1)
		return;

	std::deque<int> smallContainer, bigContainer;

	splitPairs(container, smallContainer, bigContainer);
	fordJohnsonSort(bigContainer);
	binaryInsert(smallContainer, bigContainer);

	container = bigContainer;
	_finalDequeContainer = bigContainer;
}

void	PmergeMe::binaryInsert(std::deque<int>& src, std::deque<int>& dst) {
	for (size_t i = 0; i < src.size(); ++i) {
		std::deque<int>::iterator it = std::lower_bound(
			dst.begin(), dst.end(), src[i]);
		dst.insert(it, src[i]);
	}
}

// Optimized version, complexity o(n)
void	deleteDuplicates(std::deque<int>& container) {
	std::set<int> seenValues;
	std::deque<int>	result;
	
	for (size_t i = 0; i < container.size(); ++i) {
		if (seenValues.find(container[i]) == seenValues.end()) {
			seenValues.insert(container[i]);
			result.push_back(container[i]);
		}
	}
	container = result;
}

void	parseArgs(std::deque<int>& container, char **av) {
	for (size_t i = 0; av[i]; ++i) {
		if (!isNumber(av[i]))
			throw std::invalid_argument("argument is not a number.");
		if (!isIntRange(av[i]))
			throw std::invalid_argument("argument numbers is out of int range");
		if (!isPositive(av[i]))
			throw std::invalid_argument("argument must be positive.");

		container.push_back(atoi(av[i]));
	}

	deleteDuplicates(container);
}


// VECTOR

void	PmergeMe::splitPairs(const std::vector<int>& container, std::vector<int>& smallContainer,
	std::vector<int>& bigContainer)
{
	for (size_t i = 0; i + 1 < container.size(); i += 2) {
		if (container[i] < container[i + 1]) {
			smallContainer.push_back(container[i]);
			bigContainer.push_back(container[i + 1]);
		} else {
			smallContainer.push_back(container[i + 1]);
			bigContainer.push_back(container[i]);
		}
	}
	if (container.size() % 2 != 0)
		smallContainer.push_back(container.back());
}

void	PmergeMe::fordJohnsonSort(std::vector<int>& container) {
	if (container.size() <= 1)
		return;

	std::vector<int> smallContainer, bigContainer;

	splitPairs(container, smallContainer, bigContainer);
	fordJohnsonSort(bigContainer);
	binaryInsert(smallContainer, bigContainer);

	container = bigContainer;
	_finalVectorContainer = bigContainer;
}

void	PmergeMe::binaryInsert(std::vector<int>& src, std::vector<int>& dst) {
	for (size_t i = 0; i < src.size(); ++i) {
		std::vector<int>::iterator it = std::lower_bound(
			dst.begin(), dst.end(), src[i]);
		dst.insert(it, src[i]);
	}
}

void	deleteDuplicates(std::vector<int>& container) {
	std::set<int>		seenValues;
	std::vector<int>	result;
	
	for (size_t i = 0; i < container.size(); ++i) {
		if (seenValues.find(container[i]) == seenValues.end()) {
			seenValues.insert(container[i]);
			result.push_back(container[i]);
		}
	}
	container = result;
}

void	parseArgs(std::vector<int>& container, char **av) {
	for (size_t i = 0; av[i]; ++i) {
		if (!isNumber(av[i]))
			throw std::invalid_argument("argument is not a number.");
		if (!isIntRange(av[i]))
			throw std::invalid_argument("argument numbers is out of int range");
		if (!isPositive(av[i]))
			throw std::invalid_argument("argument must be positive.");

		container.push_back(atoi(av[i]));
	}

	deleteDuplicates(container);
}

void	PmergeMe::print() {
	std::cout << "Final Container: ";

	for (size_t i = 0; i < _finalDequeContainer.size(); ++i) {
		std::cout << "[" << _finalDequeContainer[i] << "]";
		if (i != _finalDequeContainer.size() - 1)
			std::cout << ", ";
	}

	std::cout << std::endl;
}


// General methods

bool    isNumber(const std::string& arg) {
	for (size_t i = 0; i < arg.size(); ++i) {
		if (i == 0 && arg[i] == '-')
			i++;
		if (!isdigit(arg[i]))
			return false;
	}
	return true;
}

bool	isPositive(const std::string& arg) {
	int	num = std::atoi(arg.c_str());
	if (num < 0)
		return false;
	return true;
}

bool	isIntRange(const std::string& arg) {
	std::istringstream iss(arg);
	int num;

	if (!(iss >> num))
		return false;
	return true;
}
