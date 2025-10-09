#include "PmergeMe.hpp"
#include <cctype>
#include <cstdlib>

// constructors still in development, (void) to avoid make errors
PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	(void) other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	(void) other;
	return *this;
}

PmergeMe::~PmergeMe(void) {}

// Public methods

void	PmergeMe::fordJohnsonSort(std::deque<int>& container) {
	if (container.size() <= 1)
		return;

	std::deque<int> smallContainer;
	std::deque<int> bigContainer;

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
		smallContainer.push_back(container[container.size() - 1]);

	fordJohnsonSort(bigContainer);

	//TO DO: Here I've to insert smallContainer into the big one and assign this bigContainer
	//to original passed by reference
}

// General methods

bool    isNumber(const std::string& arg) {
	for (size_t i = 0; i < arg.size(); ++i) {
		if (i == 0 && arg[i] == '-')
			i++;
		if (!isdigit(arg[i])) {
			std::cerr << "Error: all arguments must be digits" << std::endl;
			return false;
		}
	}
	std::cout << "arguments are numbers" << std::endl;
	return true;
}

bool	isPositive(const std::string& arg) {
	int	num = std::atoi(arg.c_str());
	if (num < 0) {
		std::cerr << "Error: all numbers must be positive" << std::endl;
		return false;
	}
	std::cout << "arguments are positive" << std::endl;
	return true;
}