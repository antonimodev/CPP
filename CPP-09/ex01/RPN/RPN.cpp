#include "RPN.hpp"
#include <cstdlib>

RPN::RPN(void) {}

RPN::RPN(const RPN& other) {
	(void)other;
}

RPN&	RPN::operator=(const RPN& other) {
	if (this != &other)
		_numsPile = other._numsPile;
	return *this;
}

RPN::~RPN(void) {}

// ------------------- Public Methods -------------------

// char* and std::string are not the same, so char *av received isn't std::string
void	RPN::push(const char* str) {
	_numsPile.push(atoi(str));
}

void	RPN::performOperation(const char op) {
	if (_numsPile.size() < 2) {
		std::cerr << "Error: must be at least 2 numbers in stack to operate" << std::endl;
		exit(1);
	}

	int firstNum = _numsPile.top();
	_numsPile.pop();
	int secondNum = _numsPile.top();
	_numsPile.pop();

	switch (op) {
		case '+': _numsPile.push(secondNum + firstNum); break;
		case '-': _numsPile.push(secondNum - firstNum); break;
		case '*': _numsPile.push(secondNum * firstNum); break;  
		case '/':
			if (firstNum == 0) {
				std::cerr << "Error: can't divide by zero" << std::endl;
				exit(1);
			}
			_numsPile.push(secondNum / firstNum); break;
		default:
			std::cerr << "Unknown operator" << std::endl;
			exit(1);
	}
}

void	RPN::printResult(void) const {
	if (_numsPile.size() == 1)
		std::cout << _numsPile.top() << std::endl;
}

void	RPN::printStack(void) const {
	std::stack<int> copy = _numsPile;
	size_t i = 0;
	while (!copy.empty()) {
		std::cout << "[" << i << "] " << copy.top() << std::endl;
		copy.pop();
		++i;
	}
}

// ------------------- Global Functions -------------------

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
