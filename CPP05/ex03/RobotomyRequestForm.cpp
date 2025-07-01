
#include "RobotomyRequestForm.hpp"

#define RESET	"\e[0m"
#define RED		"\e[41m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", req_sign, req_exec), target("Random")
{
	std::cout << BLUE << "Default constructor called of Robotomy Form" << RESET << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm("Robotomy", req_sign, req_exec), target(_target)
{
	std::cout << BLUE << "Fields constructor called of Robotomy Form" << RESET << std::endl;
}


RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << YELLOW << "Destructor called of Robotomy Form" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), target(copy.target)
{
	std::cout << "Copy constructor called of Robotomy Form" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
	target = assign.target;
	std::cout << "Copy assignment operator called of Robotomy Form" << std::endl;
	return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
	return target;
}

int RobotomyRequestForm::action() const
{
	std::cout << "VRRRRRRRRRZZZTTTTTTT" << std::endl;
	if (std::rand() % 2)
		std::cout << target << " has been robotomized" << std::endl;
	else
	{
		std::cout << "Robotomy failed" << std::endl;
		return 1;
	}
	return 0;
}

