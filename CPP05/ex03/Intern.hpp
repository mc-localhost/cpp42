#pragma once

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

# include <iostream>
# include <string>
# include <utility>

class AForm;

class Intern
{
	class WrongFormNameException : public std::exception
	{
		public:
			const char* what() const noexcept override;
	};
	
	AForm * createPardon(std::string target);
	AForm * createRobotomy(std::string target);
	AForm * createShrubbery(std::string target);
	
	public:
		Intern();
		~Intern();
		Intern(const Intern &copy);
		Intern & operator=(Intern assign);

		AForm * makeForm(std::string name, std::string target);
};
