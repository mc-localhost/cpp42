#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "\e[0;31ma wRoNg kItT33n g0t c0n$trUcTed\e[0m" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "\e[0;31mDestructor called of WrongCat\e[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "\e[0;33mCopy Constructor of WrongCat called\e[0m" << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat assign)
{
	std::swap(_type, assign._type);
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "wiwiwi /ᐠ .⋏. ᐟ\\ ﾉ " << std::endl;
	std::cout << std::string(18, '*') << std::endl;
}
