#pragma once

#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
	const std::string name;
	const unsigned short int sign_grade;
	const unsigned short int execute_grade;
	bool is_signed;

	public:
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
		class AlreadySignedException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
		unsigned short int validateGrade(unsigned short int grade);

		Form();
		Form(std::string _name, unsigned short int _sign_grade, unsigned short int _exec_grade);
		virtual ~Form();
		Form(const Form &copy);
		Form & operator=(Form assign);

		std::string getName() const;
		bool getIsSigned() const;
		unsigned short int getSignGrade() const;
		unsigned short int getExecuteGrade() const;

		void beSigned(const Bureaucrat &bur);
};

std::ostream & operator<<(std::ostream &os, Form &form);
