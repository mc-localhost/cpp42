
#include "AForm.hpp"

#define RESET	"\e[0m"
#define RED		"\e[41m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"

const char *	AForm::GradeTooHighException::what(void) const noexcept
{
	return ("Grade too high");	
}

const char *	AForm::GradeTooLowException::what(void) const noexcept
{
	return ("Grade too low");
}

const char *	AForm::AlreadySignedException::what(void) const noexcept
{
	return ("Form is already signed");
}

const char *	AForm::NotSignedException::what(void) const noexcept
{
	return ("Form is not signed");
}

const char *	AForm::ActionFailedException::what(void) const noexcept
{
	return ("Action failed");
}

unsigned short int AForm::validateGrade(unsigned short int grade)
{
	if (grade < Bureaucrat::highest_grade)
		throw AForm::GradeTooHighException();
	else if (grade > Bureaucrat::lowest_grade)
		throw AForm::GradeTooLowException();
	return grade;
}

void AForm::beSigned(const Bureaucrat &bur)
{
	if (is_signed == true)
		throw AlreadySignedException();
	else if (bur.getGrade() > sign_grade)
		throw GradeTooLowException();
	else
		is_signed = true;
}


AForm::AForm() : name("Empty AForm"),
				sign_grade(Bureaucrat::highest_grade),
				execute_grade(Bureaucrat::highest_grade),
				is_signed(false)
{
	std::cout << BLUE << "Default constructor called of AForm" << RESET << std::endl;
}



AForm::AForm(std::string _name, unsigned short int _sign_grade, unsigned short int _exec_grade)
try :
	name(_name),
	sign_grade(validateGrade(_sign_grade)),
	execute_grade(validateGrade(_exec_grade)),
	is_signed(false)
{
	std::cout << BLUE << "Fields constructor called of AForm" << RESET << std::endl;
}
catch (const AForm::GradeTooLowException &e)
{
	// std::cerr << RED << e.what() << RESET << std::endl;
	throw;
}
catch (const AForm::GradeTooHighException &e)
{
	// std::cerr << RED << e.what() << RESET << std::endl;
	throw;
}



AForm::~AForm()
{
	std::cout << YELLOW << "Destructor called of AForm" << RESET << std::endl;
}

AForm::AForm(const AForm &copy) : name(copy.name),
									sign_grade(copy.sign_grade),
									execute_grade(copy.execute_grade),
									is_signed(false)
{
	std::cout << "Copy constructor called of AForm" << std::endl;
}

AForm & AForm::operator=(const AForm &assign)
{
	is_signed = assign.is_signed;
	std::cout << "Copy assignment operator called of AForm" << std::endl;
	return *this;
}

std::ostream & operator<<(std::ostream &os, AForm &AForm)
{
	os << "Form: " << AForm.getName();
	if (AForm.getIsSigned())
		os << ", is signed. ";
	else
		os << ", is not signed. ";
	os << "Grade required to execute: " << AForm.getExecuteGrade() << ", to sign: " << AForm.getSignGrade() << ".";
	return os;
}

std::string AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return is_signed;
}

unsigned short int AForm::getSignGrade() const
{
	return sign_grade;
}

unsigned short int AForm::getExecuteGrade() const
{
	return execute_grade;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (is_signed == false)
		throw NotSignedException();
	else if (executor.getGrade() > execute_grade)
		throw GradeTooLowException();
	else
	{
		if (this->action() != 0)
			throw ActionFailedException();
	}
}
