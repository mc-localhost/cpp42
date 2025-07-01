
#include "PresidentialPardonForm.hpp"

#define RESET	"\e[0m"
#define RED		"\e[41m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Pardon", req_sign, req_exec), target("Random")
{
	std::cout << BLUE << "Default constructor called of Pardon Form" << RESET << std::endl;
}


PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm("Pardon", req_sign, req_exec), target(_target)
{
	std::cout << BLUE << "Fields constructor called of Pardon Form" << RESET << std::endl;
}


PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << YELLOW << "Destructor called of Pardon Form" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), target(copy.target)
{
	std::cout << "Copy constructor called of Pardon Form" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &assign)
{
	target = assign.target;
	std::cout << "Copy assignment operator called of Pardon Form" << std::endl;
	return *this;
}

std::string PresidentialPardonForm::getTarget() const
{
	return target;
}

int PresidentialPardonForm::action() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return 0;
}
