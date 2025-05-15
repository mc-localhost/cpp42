#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	std::cout << "\e[0;35ma kitten got constructed\e[0m" << std::endl;
}

Cat::~Cat()
{
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "\e[0;33mCat Copy Constructor called\e[0m" << std::endl;
}

Cat & Cat::operator=(Cat assign)
{
	std::swap(_type, assign._type);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "meow /ᐠ .⋏. ᐟ\\ ﾉ " << std::endl;
	std::cout << std::string(18, '*') << std::endl;
}
