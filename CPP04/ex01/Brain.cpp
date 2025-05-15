#include "Brain.hpp"

// Constructors
Brain::Brain()
{
	_ideas = new std::string[100]{};
	std::cout << "\e[0;33mDefault Constructor called of Brain\e[0m" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	_ideas = new std::string[100]{};
	for (int i = 0; i < 100; ++i)
	{
		_ideas[i] = copy._ideas[i];
	}
	std::cout << "\e[0;33mCopy Constructor called of Brain\e[0m" << std::endl;
}

// Destructor
Brain::~Brain()
{
	delete[] _ideas;
	std::cout << "\e[0;31mDestructor called of Brain\e[0m" << std::endl;
}

// Operators
Brain & Brain::operator=(Brain assign)
{
	std::swap(_ideas, assign._ideas);
	return *this;
}

void Brain::addFirstIdea(std::string idea)
{
	_ideas[0] = idea;
}

void Brain::printFirstIdea() const
{
	std::cout << _ideas[0] << std::endl;
}
