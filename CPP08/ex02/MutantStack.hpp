#pragma once

#include <iostream>
#include <algorithm>
#include <stack>
#include <numeric>

template <typename T>
class MutantStack : public std::stack<T>
{

	public:
		MutantStack();
		virtual ~MutantStack();
		MutantStack(const MutantStack &copy);
		MutantStack & operator=(const MutantStack &assign);

		void printNumbers() const;
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin();
		iterator end();
};

#include "MutantStack.tpp"