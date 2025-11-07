#include "RPN.hpp"
#include <cstdlib>
#include <sstream>
#include <climits>


RPN::RPN(void) {}


RPN::RPN(const RPN& other) : _numsPile(other._numsPile) {}


RPN&	RPN::operator=(const RPN& other) {
	if (this != &other)
		_numsPile = other._numsPile;
	return *this;
}


RPN::~RPN(void) {}


// ------------------- Public -------------------


void	RPN::push(std::string& arg) {
	_numsPile.push(atoi(arg.c_str()));
}


void	RPN::performOperation(std::string& op) {
	if (_numsPile.size() < 2) {
		std::cerr << "Error: must be at least 2 numbers in stack to operate" << std::endl;
		exit(1);
	}

	long long firstNum = _numsPile.top();
	_numsPile.pop();
	long long secondNum = _numsPile.top();
	_numsPile.pop();

	long long result;

	switch (op[0]) {
		case '+': result = secondNum + firstNum; break;
		case '-': result = secondNum - firstNum; break;
		case '*': result = secondNum * firstNum; break;
		case '/':
			if (firstNum == 0) {
				std::cerr << "Error: can't divide by zero" << std::endl;
				exit(1);
			}
			result = secondNum / firstNum;
			break;
		default:
			std::cerr << "Error: bad operations" << std::endl;
			exit(1);
	}

	if (result < INT_MIN || result > INT_MAX) {
		std::cerr << "Error: number out of int range" << std::endl;
		exit(1);
	}

	_numsPile.push(static_cast<int>(result));
}


void	RPN::processCalc(char *av, RPN& polishCalc) {
	std::istringstream iss(av);
	std::string	arg;

	while (iss >> arg && isValid(arg)) {
		if (isNumber(arg)) {
			polishCalc.push(arg);
			continue;
		}
		polishCalc.performOperation(arg);
	}
}


void	RPN::printResult(void) const {
	if (_numsPile.empty()) {
		std::cerr << "Error: empty or invalid expression" << std::endl;
		exit(1);
	}
	if (_numsPile.size() > 1) {
		std::cerr << "Error: invalid expression (remaining numbers in stack)" << std::endl;
		exit(1);
	}
	std::cout << _numsPile.top() << std::endl;
}


void	RPN::printStack(void) const {
	std::stack<int> copy = _numsPile;

	for (size_t i = 0; !copy.empty(); ++i) {
		std::cout << "[" << i << "] " << copy.top() << std::endl;
		copy.pop();
	}
}


// ------------------- General -------------------


bool isNumber(const std::string& arg) {
	if (arg.empty())
		return false;
	if (arg == "-")
		return false;
	for (size_t i = 0; i < arg.size(); ++i) {
		if (i == 0 && arg[i] == '-')
			continue;
		if (!isdigit(arg[i]))
			return false;
	}
	return true;
}


bool isOperator(const std::string& arg) {
	return ((arg.size() == 1)
		&&	(arg[0] == '+'
		||	arg[0] == '-'
		||	arg[0] == '*'
		||	arg[0] == '/'));
}


bool	isValid(std::string& arg) {
	if (isOperator(arg))
		return true;

	if (isNumber(arg)) {
		std::istringstream iss(arg);
		int num;

		iss >> num;
		if (num > 9) {
			std::cerr << "Error: 9 is max value allowed" << std::endl;
			exit(1);
		}

		return true;
	}

	std::cerr << "Error: Args must be numbers or arithmetic op (+, -, *, /)" << std::endl;
	exit(1);
}


/* void	RPN::processCalc(char *av, RPN& polishCalc) {
	std::istringstream iss(av);
	std::string	arg;

	int	argNums = 0;
	while (iss >> arg && isValid(arg)) {
		if (isNumber(arg)) {
			argNums++;
			if (argNums > 9) {
				std::cerr << "Error: numbers quantity must be between 0-9" << std::endl;
				exit(1);
			}
			polishCalc.push(arg);
			continue;
		}
		polishCalc.performOperation(arg);
	}
} */
