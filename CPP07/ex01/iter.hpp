#pragma once

#include <iostream> // size_t included there

template <typename T, typename F>
void iter(T *a_add, size_t size, F func)
{
	for (size_t i = 0; i < size; i++)
		func(a_add[i]);
}
