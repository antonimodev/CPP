#include "PmergeMe.hpp"
#include <cstdlib>

static void	printDeque(std::deque<int>& container) {
	std::cout << "Container without duplicates: ";
	for (size_t i = 0; i < container.size(); ++i) {
		std::cout << "[" << container[i] << "]";
		if (i != container.size() - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
}

int	main(int ac, char **av) {
	if (ac == 1) {
		std::cerr << "Error: usage: ./pmergeme <numbers>" << std::endl;
		return 1;
	}
	av++;

	std::deque<int> container;
	parseArgs(container, av);
	deleteDuplicates(container);
	printDeque(container); // debugging

	PmergeMe algorithm = PmergeMe();
	algorithm.fordJohnsonSort(container);

	algorithm.print();
	return 0;
}