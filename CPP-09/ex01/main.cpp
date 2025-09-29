#include "RPN.hpp"
#include <stack>

/* EXAMPLES
2 3 + -> 5
2 3 4 * + -> 14
5 1 2 + 4 * + 3 - -> 14
2 + -> ERROR
-3 -2 * -> 6
*/

int main(int ac, char **av) {
	if (ac <= 1) {
		std::cerr << "Error: usage: ./RPN <num1> <num2> <arithmetic op>" << std::endl;
		return 1;
	}
	av++;

	RPN polishCalc;
	while (av && *av) {
		if (!isNumber(*av) && !isOperator(*av)) {
			std::cerr << "Error: args must be numbers and arithmetic operators" << std::endl;
			return 1;
		}
		if (isNumber(*av))
			polishCalc.push(*av);
		else if (isOperator(*av))
			polishCalc.performOperation(**av);
		av++;
	}
	// polishCalc.printStack(); debug
	polishCalc.printResult();
	return 0;
}