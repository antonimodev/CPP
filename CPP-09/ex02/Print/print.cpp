#include "print.hpp"
#include <ctime>

// ------------- Deque -------------
void	printAfter(std::deque<int>& container) {
	std::cout << "After:";

	std::deque<int>::iterator it = container.begin();
	for (; it != container.end(); ++it) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}


// ------------- Vector -------------
void	printAfter(std::vector<int>& container) {
	std::cout << "After:";

	std::vector<int>::iterator it = container.begin();
	for (; it != container.end(); ++it) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}


// ------------- General -------------
void	printBefore(int ac, char **av) {
	std::cout << "Before:";

	for (int i = 0; i < ac - 1; ++i)
		std::cout << " " << av[i];

	std::cout << std::endl;
}


void	printMsg(clock_t start, clock_t end, int ac) {
	double elapsed_time = static_cast<double>(end - start) * (CLOCKS_PER_SEC / 10000000000.0);
	
	std::cout << "Time to process a range of "
	<< (ac - 1) << " elements with std::vector: "
	<< elapsed_time << " us" << std::endl;
}
