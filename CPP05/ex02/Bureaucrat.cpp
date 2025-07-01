# include "Bureaucrat.hpp"

#define RESET	"\e[0m"
#define RED		"\e[41m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"

const char *	Bureaucrat::GradeTooHighException::what(void) const noexcept
{
	return ("Grade too high: must be at least 1");	
}

const char *	Bureaucrat::GradeTooLowException::what(void) const noexcept
{
	return ("Grade too low: must be no more than 150");
}

unsigned short int Bureaucrat::validateGrade(unsigned short int grade)
{
	if (grade < highest_grade)
		throw GradeTooHighException();
	else if (grade > lowest_grade)
		throw GradeTooLowException();
	return grade;
}

Bureaucrat::Bureaucrat() : name("No Name"), grade(lowest_grade)
{
	std::cout << BLUE << "Default constructor called of Bureaucrat" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string _name, unsigned short int _grade) : name(_name)
{
	try
	{
		grade = validateGrade(_grade);
	}
	catch(const GradeTooLowException& e)
	{
		// std::cerr << RED << e.what() << RESET << std::endl;
		throw;
	}
	catch(const GradeTooHighException& e)
	{
		// std::cerr << RED << e.what() << RESET << std::endl;
		throw;
	}
	std::cout << BLUE << "Fields constructor called of Bureaucrat" << RESET << std::endl;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << YELLOW << "Destructor called of Bureaucrat" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade)
{
	std::cout << "Copy constructor called of Bureaucrat" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat assign)
{
	std::swap(grade, assign.grade);
	std::cout << "Copy assignment operator called of Bureaucrat" << std::endl;
	return *this;
}

std::string Bureaucrat::getName() const
{
	return name; 
}
unsigned short int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->grade == highest_grade)
		throw GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade == lowest_grade)
		throw GradeTooLowException();
	this->grade++;
}
void Bureaucrat::signAForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << name << " signed " << f.getName() << std::endl;
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cout << name << " couldn't sign the form " << f.getName() << " because: ";
		std::cerr << e.what() << std::endl;
	}
	catch (const AForm::AlreadySignedException& e)
	{
		std::cout << name << " couldn't sign the form " << f.getName() << " because: ";
		std::cerr << e.what() << RESET << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cout << name << " couldn't execute the form " << form.getName() << " because: ";
		std::cerr << e.what() << std::endl;
	}
	catch(const AForm::NotSignedException& e)
	{
		std::cout << name << " couldn't execute the form " << form.getName() << " because: ";
		std::cerr << e.what() << std::endl;
	}
	catch(const AForm::ActionFailedException& e)
	{
		std::cout << name << " couldn't execute the form " << form.getName() << " because: ";
		std::cerr << e.what() << std::endl;
	}
}


std::ostream & operator << (std::ostream &os, const Bureaucrat &bur)
{
	return os << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
}
