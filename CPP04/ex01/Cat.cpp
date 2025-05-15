#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	brain = new Brain();
	brain->addFirstIdea("if i meow long enough i'll get food");
	std::cout << "\e[0;35ma kitten got constructed\e[0m" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	brain = new Brain(*copy.brain);
	std::cout << "\e[0;33mCat Copy Constructor called\e[0m" << std::endl;
}

Cat & Cat::operator=(Cat assign)
{
	std::swap(_type, assign._type);
	std::swap(brain, assign.brain);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "meow /ᐠ .⋏. ᐟ\\ ﾉ " << std::endl;
	std::cout << std::string(18, '*') << std::endl;
}

Brain & Cat::getBrain() const
{
	return *brain;
}
