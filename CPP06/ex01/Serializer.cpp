#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
	auto original_flags = std::cout.flags();
    std::cout << "before serializing: " << std::showbase << std::hex << ptr << '\n';

	std::uintptr_t raw = reinterpret_cast<std::uintptr_t>(ptr);

	std::cout.flags(original_flags);
    std::cout << "serialize result: " << raw << '\n';

	return raw;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	auto original_flags = std::cout.flags();
	std::cout << "before deserializing: " << raw << '\n';

	Data *ptr = reinterpret_cast<Data*>(raw);

	std::cout << "deserialize result: " << std::showbase << std::hex << ptr << '\n';
	std::cout.flags(original_flags);

	return ptr;
}
