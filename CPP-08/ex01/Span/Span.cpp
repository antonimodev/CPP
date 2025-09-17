#include <iostream>
#include <algorithm>

#include "Span.hpp"

Span::Span(unsigned int n) : _limits(n) {
	_vector.reserve(n);
}

Span::Span(const Span& other) : _vector(other._vector), _limits(other._limits) {}

Span&  Span::operator=(const Span& other) {
	if (this != &other) {
		_vector = other._vector;
		_limits = other._limits;
	}
	return *this;
}

Span::~Span(void) {}

void	Span::addNumber(int num) {
	if (_vector.size() == _limits)
		throw std::runtime_error("Limit reached, can't add more numbers");
	_vector.push_back(num);
}

// Both functions creates tmp to maintain original order and not modify main vector
int Span::shortestSpan(void) {
	if (_vector.empty())
		throw std::runtime_error("No values in Span class");
	if (_vector.size() == 1)
		throw std::runtime_error("There is only 1 value");

	std::vector<int> tmp_vector = _vector;
	std::sort(tmp_vector.begin(), tmp_vector.end());
	int result = tmp_vector[1] - tmp_vector[0];

	for (size_t i = 1; i < tmp_vector.size() - 1; ++i) {
		if (tmp_vector[i + 1] - tmp_vector[i] < result)
			result = tmp_vector[i + 1] - tmp_vector[i];
	}
	return result;
}

int		Span::longestSpan(void) {
	if (_vector.empty())
		throw std::runtime_error("No values in Span class");
	if (_vector.size() == 1)
		throw std::runtime_error("There is only 1 value");

	std::vector<int> tmp_vector = _vector;
	std::sort(tmp_vector.begin(), tmp_vector.end());
	return (tmp_vector[tmp_vector.size() - 1] - tmp_vector[0]);
}