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

	// Delete duplicated numbers, comparing each element with the other ones
	for (size_t i = 0; i < container.size(); ++i) {
		for (size_t j = i + 1; j < container.size(); ) {
			if (container[i] == container[j])
				container.erase(container.begin() + j); // erase requires iterator, not literal pos
			else
				++j;
		}
	}

	// Distribute small and big numbers of each pair to their corresponding deque
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

	PmergeMe algorithm = PmergeMe();
	algorithm.fordJohnsonSort(bigContainer);
	// Just for printing
	std::cout << "Big container: " << std::endl;
	for (size_t i = 0; i < bigContainer.size(); ++i)
		std::cout << bigContainer[i] << std::endl;
	return 0;
}