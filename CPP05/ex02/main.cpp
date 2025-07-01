#include "Bureaucrat.hpp"
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
	
	// ShrubberyCreationForm: Required grades: sign 145, exec 137
	ShrubberyCreationForm test_shrubbery("home");
	std::cout << test_shrubbery << std::endl;
	// RobotomyRequestForm: Required grades: sign 72, exec 45
	RobotomyRequestForm test_robotomy("Poor soul");
	std::cout << test_robotomy << std::endl;
	// PresidentialPardonForm: Required grades: sign 25, exec 5
	PresidentialPardonForm test_presidential("John Doe");
	std::cout << test_presidential << std::endl;

	std::cout << std::endl << "*	*	*	*	*" << std::endl << std::endl;
	PresidentialPardonForm test_presidential_copy(test_presidential);
	std::cout << test_presidential_copy << std::endl;

	std::cout << std::endl << "*	*	*	*	*" << std::endl << std::endl;
	try
	{
		Bureaucrat nobody("Nobody", 146);
		std::cout << nobody << std::endl;
		nobody.signAForm(test_shrubbery);
		nobody.executeForm(test_shrubbery);
		std::cout << PURPLE << "Increasing grade to sign..." << RESET << std::endl;
		nobody.incrementGrade();
		std::cout << PURPLE << "Grade after increment: " << nobody.getGrade() << RESET << std::endl;
		nobody.signAForm(test_shrubbery);
		nobody.executeForm(test_shrubbery);
	
		std::cout << std::endl << "*	*	*	*	*" << std::endl << std::endl;
		Bureaucrat mister("Important Person", 1);
		std::cout << mister << std::endl;
		std::cout << PURPLE << "he can basically sign and execute anything" << RESET << std::endl;
		mister.signAForm(test_shrubbery);
		mister.signAForm(test_robotomy);
		mister.signAForm(test_presidential);
		mister.executeForm(test_shrubbery);
		mister.executeForm(test_robotomy);
		mister.executeForm(test_presidential);
		mister.executeForm(test_presidential_copy);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	return 0;
}
