#include "EasyFind.hpp"

// ++it is more efficient way to work with containers, it avoids create temp copy, and it compares actual value
template <typename T>
int easyFind(T& container, int num) {
	typename T::iterator it;
	for (it = container.begin(); it != container.end(); ++it) {
		if (*it == num)
			return *it;
	}
	throw std::runtime_error("Value not finded"); // throw an exception
}