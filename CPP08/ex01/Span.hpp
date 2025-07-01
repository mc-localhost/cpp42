#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

class Span
{
	unsigned int capacity;
	std::vector<int> v;

	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span &copy);
		Span & operator=(Span assign);

		class NElementsException : public std::exception
		{
			public:
				const char *what() const noexcept override;
		};
		class SpanEmptyException : public std::exception
		{
			public:
				const char *what() const noexcept override;
		};

		void addNumber(const int num);
		void addManyNumbers(std::vector<int> to_insert);
		void addRandomNumbers(const unsigned int count);
		long int shortestSpan() const;
		long int longestSpan() const;

		void printNumbers() const;
};
