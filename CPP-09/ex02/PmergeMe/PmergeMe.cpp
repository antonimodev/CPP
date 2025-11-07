#include "PmergeMe.hpp"
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <stdexcept>
#include <set>


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


// JACOBSTHAL SEQUENCE IMPLEMENTATION
void	PmergeMe::generateJacobsthalSequence(std::vector<size_t>& sequence, size_t limit) {
	if (limit == 0)
		return;

	size_t jacob_prev = 0; // J(0) = 0
	size_t jacob_curr = 1; // J(1) = 1

	while (jacob_curr < limit) {
		sequence.push_back(jacob_curr);
		size_t jacob_next = jacob_curr + 2 * jacob_prev; // J(n) = J(n-1) + 2 * J(n-2)
		jacob_prev = jacob_curr;
		jacob_curr = jacob_next;
	}
}


void	PmergeMe::generateInsertionOrder(std::vector<size_t>& insertionIndexes, size_t elementsToInsert) {
    if (elementsToInsert == 0)
        return;

    std::vector<size_t> jacobsthalPositions;
    generateJacobsthalSequence(jacobsthalPositions, elementsToInsert);

    std::vector<bool> alreadyInserted(elementsToInsert, false);
    size_t previousJacob = 0;

    for (size_t i = 0; i < jacobsthalPositions.size(); ++i) {
        size_t currentJacob = jacobsthalPositions[i];
        size_t endRange = (currentJacob <= elementsToInsert) ? currentJacob : elementsToInsert;

        for (size_t pos = endRange; pos > previousJacob; --pos) {
            size_t idx = pos - 1;
            if (!alreadyInserted[idx]) {
                insertionIndexes.push_back(idx);
                alreadyInserted[idx] = true;
            }
        }
        previousJacob = currentJacob;
    }

    for (size_t i = 0; i < elementsToInsert; ++i) {
        if (!alreadyInserted[i])
            insertionIndexes.push_back(i);
    }
}


// ------------- Deque -------------

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
	binaryInsertWithJacobsthal(smallContainer, bigContainer);

	container = bigContainer;
	_finalDequeContainer = bigContainer;
}


void	PmergeMe::binaryInsertWithJacobsthal(std::deque<int>& src, std::deque<int>& dst) {
	if (src.empty())
		return;

	std::vector<size_t> insertionOrder;
	generateInsertionOrder(insertionOrder, src.size());

	for (size_t i = 0; i < insertionOrder.size(); ++i) {
		size_t idx = insertionOrder[i];
		std::deque<int>::iterator it = std::lower_bound(
			dst.begin(), dst.end(), src[idx]);
		dst.insert(it, src[idx]);
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


// ------------- Vector -------------

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
	binaryInsertWithJacobsthal(smallContainer, bigContainer);

	container = bigContainer;
	_finalVectorContainer = bigContainer;
}


void	PmergeMe::binaryInsertWithJacobsthal(std::vector<int>& src, std::vector<int>& dst) {
	if (src.empty())
		return;

	std::vector<size_t> insertionOrder;
	generateInsertionOrder(insertionOrder, src.size());

	for (size_t i = 0; i < insertionOrder.size(); ++i) {
		size_t idx = insertionOrder[i];
		std::vector<int>::iterator it = std::lower_bound(
			dst.begin(), dst.end(), src[idx]);
		dst.insert(it, src[idx]);
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


// ------------- General -------------
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
