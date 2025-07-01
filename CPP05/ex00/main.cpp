#include "Bureaucrat.hpp"

#define RESET	"\e[0m"
#define RED		"\e[41m"

int main(void)
{
	std::cout << "*	Default constructor check	*" << std::endl;
	Bureaucrat test;
	std::cout << std::endl << "*	*	*	*	*" << std::endl << std::endl;
	try
	{
		Bureaucrat nobody("Nobody", 1200);
		std::cout << nobody << std::endl;
		nobody.decrementGrade();
		std::cout << "Grade after decrement: " << nobody.getGrade() << std::endl;
		nobody.incrementGrade();
		std::cout << "Grade after increment: " << nobody.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << std::endl << "*	*	*	*	*" << std::endl << std::endl;
	try
	{
		Bureaucrat mister("Important Person", 1);
		std::cout << mister << std::endl;
		mister.incrementGrade();
		std::cout << "Grade after increment: " << mister.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	return 0;
}