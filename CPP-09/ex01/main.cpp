#include "RPN.hpp"
#include <stack>
#include <cstdlib>


int main(int ac, char **av) {
	if (ac != 2 || !av || !av[1] || av[1][0] == '\0') {
		std::cerr << "Error: usage: ./RPN \"<num1> <num2> <arithmetic op>\"" << std::endl;
		return 1;
	}

	RPN polishCalc;
	polishCalc.processCalc(av[1], polishCalc);
	polishCalc.printResult();

	return 0;
}
