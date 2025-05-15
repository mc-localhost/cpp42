#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	std::cout << "\e[0;34ma puppy got constructed\e[0m" << std::endl;
}

Dog::~Dog()
{
	std::cout << "\e[0;31mDestructor called of Dog\e[0m" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "woof ᐡ ᐧ ﻌ ᐧ ᐡ" << std::endl;
	std::cout << std::string(18, '*') << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "\e[0;33mDog Copy Constructor called\e[0m" << std::endl;
}

Dog & Dog::operator=(Dog assign)
{
	std::swap(_type, assign._type);
	return *this;
}