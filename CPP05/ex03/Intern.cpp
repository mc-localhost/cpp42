# include "Intern.hpp"

#define RESET	"\e[0m"
#define RED		"\e[41m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"

Intern::Intern()
{
	std::cout << BLUE << "Default constructor called of Intern" << RESET << std::endl;
}

Intern::~Intern()
{
	std::cout << YELLOW << "Destructor called of Intern" << RESET << std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
	std::cout << "Copy constructor called of Intern" << std::endl;
}

Intern & Intern::operator=(Intern assign)
{
	(void)assign;
	std::cout << "Copy assignment operator called of Intern" << std::endl;
	return *this;
}

AForm * Intern::createPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm * Intern::createRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm * Intern::createShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

const char *	Intern::WrongFormNameException::what(void) const noexcept
{
	return ("Invalid form name");	
}

AForm * Intern::makeForm(std::string name, std::string target)
{
	AForm * (Intern::*func_array[3])(std::string) = {
		&Intern::createPardon, &Intern::createRobotomy, &Intern::createShrubbery
	};
	std::string forms_array[3]
	{
		"presidential pardon", "robotomy request", "shrubbery"
	};
	for (int i = 0; i < 3; ++i)
	{
		if (name == forms_array[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*func_array[i])(target);
		}
	}
	std::cout << "Intern couldn't create a form called: " << name << std::endl;
	throw WrongFormNameException();
}
