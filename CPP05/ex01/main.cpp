#include "Bureaucrat.hpp"
#include "Form.hpp"

#define RESET	"\e[0m"
#define RED		"\e[41m"

int main(void)
{
	Form test;
	std::cout << test << std::endl;
	Form test_copy = test;
	std::cout << test_copy << std::endl;

	try
	{
		Form important_form("Important Form", 10, 1);
		std::cout << important_form << std::endl;
		std::cout << std::endl << "*	*	*	*	*" << std::endl << std::endl;
		Bureaucrat nobody("Nobody", 120);
		std::cout << nobody << std::endl;
		nobody.signForm(test);
		nobody.signForm(important_form);
		
		std::cout << std::endl << "*	*	*	*	*" << std::endl << std::endl;
		Bureaucrat mister("Important Person", 1);
		std::cout << mister << std::endl;
		mister.signForm(test);
		std::cout << "Trying to sign again..." << std::endl;
		mister.signForm(test);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	return 0;
}
