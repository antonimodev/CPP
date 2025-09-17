#include <iostream>
#include <list>

#include "MutantStack.hpp"

int main(void) {
	MutantStack<int> mstack;

	mstack.push(20);
	mstack.push(10);
	mstack.push(30);

	std::cout << "MutantStack: " << std::endl;
	MutantStack<int>::iterator it;
	for (it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << std::endl;

	std::cout << "List: " << std::endl;
	std::list<int> lst;
	lst.push_back(20);
	lst.push_back(10);
	lst.push_back(30);

	std::list<int>::iterator lst_it;
	for (lst_it = lst.begin(); lst_it != lst.end(); ++lst_it)
		std::cout << *lst_it << std::endl;
	return 0;
}