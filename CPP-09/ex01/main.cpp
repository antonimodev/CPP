#include "RPN.hpp"
#include <sstream>
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
	RPN polishCalc;
	av++;

	if (ac == 2) {
		std::istringstream iss(*av);
		std::string arg;

		while (iss >> arg) {
			// this can be a little bit tricky in terms of understanding
			/* if (arg.size() == 2 && arg[0] != '-') {
				std::cerr << "Error: numbers must be 1 digit" << std::endl;
				return 1;
			} */
			if (isNumber(arg.c_str()))
				polishCalc.push(arg.c_str());
			else if (isOperator(arg.c_str()))
				polishCalc.performOperation(arg[0]);
			else {
				std::cerr << "Error: args must be numbers and arithmetic operators" << std::endl;
				return 1;
			}
		}
	} else {
		while (av && *av) {
			if (isNumber(*av))
				polishCalc.push(*av);
			else if (isOperator(*av))
				polishCalc.performOperation(**av);
			else {
				std::cerr << "Error: args must be numbers and arithmetic operators" << std::endl;
				return 1;
			}
			av++;
		}
	}
	//polishCalc.printStack();
	polishCalc.printResult();
	return 0;
}