#include "RPN.hpp"
#include <stack>
#include <cstdlib>


int main(int ac, char **av) {
	if (ac != 2 || !av || av[1][0] == '\0' || av[1] == NULL) {
		std::cerr << "Error: usage: ./RPN \"<num1> <num2> <arithmetic op>\"" << std::endl;
		return 1;
	}
	av++;

	RPN polishCalc;
	polishCalc.processCalc(*av, polishCalc);
	polishCalc.printResult();

	return 0;
}
