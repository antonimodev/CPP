#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void) {}

Base*	Base::generate(void) {
	int random = std::rand() % 3;
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void	Base::identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	Base::identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p); // (void) casting to avoid warnings from compiler
		std::cout << "A" << std::endl;
	} catch(...) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch(...) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch(...) {}
}