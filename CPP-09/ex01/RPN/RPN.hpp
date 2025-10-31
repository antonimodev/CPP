#ifndef RPN_HPP 
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
	private:
		std::stack<int> _numsPile;

	public:
		RPN(void);
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN(void);
		
		void	push(std::string& arg);
		void	performOperation(std::string& op);
		void	processCalc(char *av, RPN& polishCalc);
		void	printStack(void) const;
		void	printResult(void) const;
	};

bool    isNumber(const std::string& arg);
bool    isOperator(const std::string& arg);
bool	isValid(std::string& arg);

#endif
