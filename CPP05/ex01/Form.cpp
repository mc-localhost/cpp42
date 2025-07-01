
#include "Form.hpp"

#define RESET	"\e[0m"
#define RED		"\e[41m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"

const char *	Form::GradeTooHighException::what(void) const noexcept
{
	return ("Grade too high");	
}

const char *	Form::GradeTooLowException::what(void) const noexcept
{
	return ("Grade too low");
}

const char *	Form::AlreadySignedException::what(void) const noexcept
{
	return ("Form is already signed");
}

unsigned short int Form::validateGrade(unsigned short int grade)
{
	if (grade < Bureaucrat::highest_grade)
		throw Form::GradeTooHighException();
	else if (grade > Bureaucrat::lowest_grade)
		throw Form::GradeTooLowException();
	return grade;
}

void Form::beSigned(const Bureaucrat &bur)
{
	if (is_signed == true)
		throw AlreadySignedException();
	else if (bur.getGrade() > sign_grade)
		throw GradeTooLowException();
	else
		is_signed = true;
}

Form::Form() : name("Empty Form"),
				sign_grade(Bureaucrat::highest_grade),
				execute_grade(Bureaucrat::highest_grade),
				is_signed(false)
{
	std::cout << BLUE << "Default constructor called of Form" << RESET << std::endl;
}


Form::Form(std::string _name, unsigned short int _sign_grade, unsigned short int _exec_grade)
try :
	name(_name),
	sign_grade(validateGrade(_sign_grade)),
	execute_grade(validateGrade(_exec_grade)),
	is_signed(false)
{
	std::cout << BLUE << "Fields constructor called of Form" << RESET << std::endl;
}
catch (const Form::GradeTooLowException &e)
{
	// std::cerr << RED << e.what() << RESET << std::endl;
	throw;
}
catch (const Form::GradeTooHighException &e)
{
	// std::cerr << RED << e.what() << RESET << std::endl;
	throw;
}



Form::~Form()
{
	std::cout << YELLOW << "Destructor called of Form" << RESET << std::endl;
}

Form::Form(const Form &copy) : name(copy.name),
								sign_grade(copy.sign_grade),
								execute_grade(copy.execute_grade),
								is_signed(false)
{
	std::cout << "Copy constructor called of Form" << std::endl;
}

Form & Form::operator=(Form assign)
{
	std::swap(is_signed, assign.is_signed);
	std::cout << "Copy assignment operator called of Form" << std::endl;
	return *this;
}

std::ostream & operator<<(std::ostream &os, Form &form)
{
	os << "Form: " << form.getName();
	if (form.getIsSigned())
		os << ", is signed. ";
	else
		os << ", is not signed. ";
	os << "Grade required to execute: " << form.getExecuteGrade() << ", to sign: " << form.getSignGrade() << ".";
	return os;
}

std::string Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return is_signed;
}

unsigned short int Form::getSignGrade() const
{
	return sign_grade;
}

unsigned short int Form::getExecuteGrade() const
{
	return execute_grade;
}
