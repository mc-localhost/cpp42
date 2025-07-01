#pragma once

#include <iostream>

template <typename T>
class Array
{
	unsigned int m_size;
	T* arr;
 
	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(const Array &copy);
		Array & operator=(const Array &assign);
		T & operator[](unsigned int i);
		const T & operator[](unsigned int i) const;
		unsigned int size() const;

		class OutOfBoundsException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
};

#include "Array.tpp"