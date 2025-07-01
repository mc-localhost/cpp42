#pragma once

# include "Form.hpp"

# include <iostream>
# include <string>
# include <utility>

class Form;

class Bureaucrat
{
	const std::string name;
	unsigned short int grade;

	public:
		static unsigned short int const	highest_grade = 1;
		static unsigned short int const	lowest_grade = 150;
		unsigned short int validateGrade(unsigned short int grade);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
			
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

		Bureaucrat();
		Bureaucrat(std::string _name, unsigned short int _grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat & operator=(Bureaucrat assign);

		std::string getName() const;
		unsigned short int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		void signForm(Form &f);
};

std::ostream & operator<<(std::ostream &os, const Bureaucrat &bur);
