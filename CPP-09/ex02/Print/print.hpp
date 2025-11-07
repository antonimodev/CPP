#pragma once

#include "PmergeMe.hpp"

enum e_container {
	DEQUE,
	VECTOR
};

// DEQUE
void	printAfter(std::deque<int>& container);


// VECTOR
void	printAfter(std::vector<int>& container);


// GENERAL
void	printBefore(int ac, char **av);
void	printMsg(e_container type, clock_t start, clock_t end, int ac);

template <typename Container>
void	printContainerStatement(int ac, char **av, Container& container) {
	printBefore(ac, av);
	printAfter(container);
}
