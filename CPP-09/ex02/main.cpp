#include "PmergeMe.hpp"
#include <cstdlib>

int	main(int ac, char **av) {
	if (ac == 1) {
		std::cerr << "Error: usage: ./pmergeme <numbers>" << std::endl;
		return 1;
	}
	av++;

	std::deque<int> container;
	parseArgs(container, av);
	deleteDuplicates(container);

	PmergeMe algorithm = PmergeMe();
	algorithm.splitPairs(container);
	algorithm.fordJohnsonSort();

	algorithm.print();
	return 0;
}