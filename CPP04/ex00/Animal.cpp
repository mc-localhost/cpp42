#include "Animal.hpp"

// Constructors
Animal::Animal()
{
	std::cout << "\e[0;33mDefault Constructor called of Animal\e[0m" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	_type = copy._type;
	std::cout << "\e[0;33mCopy Constructor called of Animal\e[0m" << std::endl;
}

Animal::Animal( std::string type)
{
	_type = type;
	std::cout << "\e[0;33mFields Constructor called of Animal\e[0m" << std::endl;
}


// Destructor
Animal::~Animal()
{
	std::cout << "\e[0;31mDestructor called of Animal\e[0m" << std::endl;
}


// Operators
Animal & Animal::operator=(const Animal &assign)
{
	if (this == &assign)
		return *this;
	_type = assign._type;
	return *this;
}


// Getters / Setters
 std::string Animal::getType() const
{
	return _type;
}
void Animal::setType( std::string type)
{
	_type = type;
}


void Animal::makeSound() const
{
	std::cout << "[deep, determined breathing]" << std::endl;
}