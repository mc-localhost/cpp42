#pragma once

#include <algorithm>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T& t, int i)
{
	auto found = std::find(t.begin(), t.end(), i);
	if (found != t.end())
		return found;
	else
		throw std::runtime_error("Value not found in container");
}

template <typename T>
typename T::const_iterator easyfind(const T& t, int i)
{
	auto found = std::find(t.begin(), t.end(), i);
	if (found != t.end())
		return found;
	else
		throw std::runtime_error("Value not found in container");
}