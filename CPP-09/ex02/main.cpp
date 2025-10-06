#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	(void) ac;
	av++;
	while (av && *av) {
		if (!isNumber(*av))
			return 1;
		if (!isPositive(*av))
			return 1;
		av++;
	} 
	return 0;
}