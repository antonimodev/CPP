#include "PmergeMe.hpp"
#include "print.hpp"
#include <cstdlib>
#include <ctime>

int	main(int ac, char **av) {
	if (ac == 1) {
		std::cerr << "Error: usage: ./pmergeme <numbers>" << std::endl;
		return 1;
	}
	av++;

	std::deque<int> dequeContainer;
	std::vector<int> vectorContainer;
	try {
		parseArgs(dequeContainer, av);
		parseArgs(vectorContainer, av);
	} catch (const std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	PmergeMe algorithm = PmergeMe();

	clock_t	startDeque = clock();
	algorithm.fordJohnsonSort(dequeContainer);
	clock_t endDeque = clock();

	printContainerStatement(ac, av, dequeContainer);

	clock_t startVector = clock();
	algorithm.fordJohnsonSort(vectorContainer);
	clock_t endVector = clock();

	printMsg(startDeque, endDeque, dequeContainer);
	printMsg(startVector, endVector, vectorContainer);
	return 0;
}