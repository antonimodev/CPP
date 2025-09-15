#include "Base.hpp"

int	main(void) {
	std::srand(std::time(0)); // Generate random sequence of numbers using actual time
	Base baseIdentifier;

	Base* p = baseIdentifier.generate();
	Base* anotherP = baseIdentifier.generate();

	baseIdentifier.identify(p);
	baseIdentifier.identify(*anotherP);

	delete p;
	delete anotherP;

	return 0;
}