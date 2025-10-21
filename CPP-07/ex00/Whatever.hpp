#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void	swap(T& firstValue, T& secondValue) {
	T temp = firstValue;
	firstValue = secondValue;
	secondValue = temp;
}

template <typename T>
T	min(const T& firstValue, const T& secondValue) {
	return (firstValue < secondValue) ? firstValue : secondValue;
}

template <typename T>
T	max(const T& firstValue, const T& secondValue) {
	return (firstValue > secondValue) ? firstValue : secondValue;
}

#endif