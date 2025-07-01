#pragma once

#include "AForm.hpp"

#include <iostream>
#include <fstream>
#include <string>


class ShrubberyCreationForm : public AForm
{
	std::string target;

	public:
		static unsigned short int const	req_sign = 145;
		static unsigned short int const	req_exec = 137;

		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string _target);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm & assign);

		std::string getTarget() const;

		int action() const override;
};
