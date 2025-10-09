#include "PmergeMe.hpp"
#include <deque>
#include <set>
#include <cstdlib>

int	main(int ac, char **av) {
	if (ac == 1) {
		std::cerr << "Error: usage: ./pmergeme <numbers>" << std::endl;
		return 1;
	}
	av++;

	std::set<int> uniqueContainer;
	for (size_t i = 0; av[i]; ++i) {
		if (!isNumber(av[i]) || !isPositive(av[i]))
			return 1;

		int num = std::atoi(av[i]);
		uniqueContainer.insert(num);
	}

	std::deque<int> container;
	for (std::set<int>::iterator it = uniqueContainer.begin(); it != uniqueContainer.end(); ++it)
		container.push_back(*it);
	uniqueContainer.clear();
	
	std::deque<int> smallContainer;
	for (size_t i = 0; i + 1 < container.size(); ++i) {
    	smallContainer.push_back(container[i] < container[i + 1] ? container[i] : container[i + 1]);
	}

	return 0;
}