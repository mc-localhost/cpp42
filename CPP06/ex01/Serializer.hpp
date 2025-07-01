#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>

#include "Data.hpp"

class Serializer
{
	Serializer() = delete;
	~Serializer() = delete;
	Serializer(const Serializer &serial) = delete;
	Serializer & operator=(const Serializer &serial) = delete;

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
