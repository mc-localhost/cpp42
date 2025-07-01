#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RESET	"\e[0m"
#define RED		"\e[41m"
#define PURPLE	"\e[35m"

int main(void)
{
	std::srand(time(nullptr));
	
	std::cout << "*	TEST FROM THE SUBJECT	*" << std::endl << std::endl;
	Intern  someRandomIntern;
    AForm*   rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf << std::endl;
	delete(rrf);
	
	std::cout << std::endl << "*	*	*	*	*" << std::endl << std::endl;
	Bureaucrat mister("Important Person", 5);
	try
	{
		AForm*  otherForm = someRandomIntern.makeForm("shrubbery", "park");
		std::cout << *otherForm << std::endl;
		mister.signAForm(*otherForm);
		mister.executeForm(*otherForm);
		delete(otherForm);
	
		AForm*   ppf = someRandomIntern.makeForm("presidential pardon", "Prisoner");
		std::cout << *ppf << std::endl;
		mister.signAForm(*ppf);
		mister.executeForm(*ppf);
		delete(ppf);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl << "*	WRONG FORM NAME CHECK	*" << std::endl << std::endl;
    try
	{
		AForm*  brokenForm = someRandomIntern.makeForm("robotomy ", "Someone");
		mister.signAForm(*brokenForm);
		delete(brokenForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	return 0;
}
