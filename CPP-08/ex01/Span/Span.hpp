#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
	private:
		std::vector<int>	_vector;
		size_t				_limits;
	
	public:
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span(void);

		void	addNumber(int num);
		int		shortestSpan(void);
		int		longestSpan(void);
};

#endif