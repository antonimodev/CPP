#include "Brain.hpp"

// std::string initialize automatically as "" empty str

Brain::Brain(void) {
	std::cout << "Brain has been initialized." << std::endl;
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];

	std::cout << "Copied successfully" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return *this;
}

Brain::~Brain(void) {
	std::cout << "Brain destroyed!." << std::endl;
}