#include "RPN.hpp"
#include <stack>
#include <cstdlib>


/* EXAMPLES
2 3 + -> 5
2 3 4 * + -> 14
5 1 2 + 4 * + 3 - -> 14
2 + -> ERROR
-3 -2 * -> 6
*/


int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: usage: ./RPN \"<num1> <num2> <arithmetic op>\"" << std::endl;
		return 1;
	}
	av++;

	RPN polishCalc;
	polishCalc.processCalc(*av, polishCalc);
	polishCalc.printResult();

	return 0;
}