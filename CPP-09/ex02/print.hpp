#pragma once

// debugging
/* static void	printDeque(std::deque<int>& container) {
	std::cout << "Container without duplicates: ";
	for (size_t i = 0; i < container.size(); ++i) {
		std::cout << "[" << container[i] << "]";
		if (i != container.size() - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
} */

void	printBefore(int ac, char **av) {
	std::cout << "Before:";

	for (int i = 0; i < ac - 1; ++i)
		std::cout << " " << av[i];

	std::cout << std::endl;
}

// DEQUE

void	printAfter(std::deque<int>& container) {
	std::cout << "After:";

	std::deque<int>::iterator it = container.begin();
	for (; it != container.end(); ++it) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

void	printMsg(clock_t start, clock_t end, std::deque<int>& container) {
	double elapsed_time = static_cast<double>(end - start) * (CLOCKS_PER_SEC / 10000000000.0);
	
	std::cout << "Time to process a range of "
	<< container.size() << " elements with std::deque: "
	<< elapsed_time << " us" << std::endl;
}


// VECTOR

void	printAfter(std::vector<int>& container) {
	std::cout << "After:";

	std::vector<int>::iterator it = container.begin();
	for (; it != container.end(); ++it) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

void	printMsg(clock_t start, clock_t end, std::vector<int>& container) {
	double elapsed_time = static_cast<double>(end - start) * (CLOCKS_PER_SEC / 10000000000.0);
	
	std::cout << "Time to process a range of "
	<< container.size() << " elements with std::vector: "
	<< elapsed_time << " us" << std::endl;
}

// GENERAL

template <typename Container>
void	printContainerStatement(int ac, char **av, Container& container) {
	printBefore(ac, av);
	printAfter(container);
}