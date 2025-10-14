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

void	PmergeMe::binaryInsert(std::deque<int>& src, std::deque<int>& dst) {
	for (size_t i = 0; i < src.size(); ++i) {
		std::deque<int>::iterator it = std::lower_bound(
			dst.begin(), dst.end(), src[i]);
		dst.insert(it, src[i]);
	}
}

void	PmergeMe::splitPairs(std::deque<int>& container) {
	for (size_t i = 0; i + 1 < container.size(); i += 2) {
		if (container[i] < container[i + 1]) {
			_smallContainer.push_back(container[i]);
			_bigContainer.push_back(container[i + 1]);
		} else {
			_smallContainer.push_back(container[i + 1]);
			_bigContainer.push_back(container[i]);
		}
	}
	if (container.size() % 2 != 0)
		_smallContainer.push_back(container[container.size() - 1]);
}

/* void	PmergeMe::fordJohnsonSort() {
	if (_bigContainer.size() <= 1)
		return;

	std::deque<int> smallCopy = _smallContainer;
	std::deque<int> bigCopy = _bigContainer;

	_smallContainer.clear();
	_bigContainer.clear();

	splitPairs(bigCopy);
	fordJohnsonSort();
	binaryInsert(_smallContainer, _bigContainer);
	binaryInsert(_smallContainer, smallCopy);

	_finalContainer = _bigContainer;
	binaryInsert(smallCopy, _finalContainer);
} */

void	PmergeMe::fordJohnsonSort() {
	if (_bigContainer.size() <= 1)
		return;

	PmergeMe foo = PmergeMe();

	foo.splitPairs(foo._bigContainer);
	foo.fordJohnsonSort();
	foo.binaryInsert(_smallContainer, _bigContainer);

	_finalContainer = _bigContainer;
}

std::deque<int>	PmergeMe::getBigContainer(void) {
	return _bigContainer;
}

std::deque<int> PmergeMe::getSmallContainer(void) {
	return _smallContainer;
}

std::deque<int> PmergeMe::getFinalContainer(void) {
	return _finalContainer;
}

void	PmergeMe::print() {
	std::cout << "Final Container: ";
	for (size_t i = 0; i < _finalContainer.size(); ++i) {
		std::cout << "[" << _finalContainer[i] << "]";
		if (i != _finalContainer.size() - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
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
	// std::cout << "arguments are numbers" << std::endl;
	return true;
}

bool	isPositive(const std::string& arg) {
	int	num = std::atoi(arg.c_str());
	if (num < 0) {
		std::cerr << "Error: all numbers must be positive" << std::endl;
		return false;
	}
	// std::cout << "arguments are positive" << std::endl;
	return true;
}

void	parseArgs(std::deque<int>& container, char **av) {
	for (size_t i = 0; av[i]; ++i) {
		if (!isNumber(av[i]) || !isPositive(av[i]))
			return;

		int num = std::atoi(av[i]);
		container.push_back(num);
	}
}

void	deleteDuplicates(std::deque<int>& container) {
    for (size_t i = 0; i < container.size(); ++i) {
        for (size_t j = i + 1; j < container.size(); ) {
            if (container[i] == container[j])
                container.erase(container.begin() + j);
            else
                ++j;
        }
	}
}