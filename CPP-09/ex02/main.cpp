#include "PmergeMe.hpp"
#include <cstdlib>

int	main(int ac, char **av) {
	if (ac == 1) {
		std::cerr << "Error: usage: ./pmergeme <numbers>" << std::endl;
		return 1;
	}
	av++;

	std::deque<int> container;
	for (size_t i = 0; av[i]; ++i) {
		if (!isNumber(av[i]) || !isPositive(av[i]))
			return 1;

		int num = std::atoi(av[i]);
		container.push_back(num);
	}
	deleteDuplicates(container);

	PmergeMe algorithm = PmergeMe();
	algorithm.splitPairs(container);
	algorithm.fordJohnsonSort();

	algorithm.print();
	return 0;
}