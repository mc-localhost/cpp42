#pragma once

#include "AForm.hpp"

#include <iostream>
#include <fstream>
#include <string>


class PresidentialPardonForm : public AForm
{
	std::string target;

	public:
		static unsigned short int const	req_sign = 25;
		static unsigned short int const	req_exec = 5;

		PresidentialPardonForm();
		PresidentialPardonForm(std::string _target);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm & operator=(const PresidentialPardonForm & assign);

		std::string getTarget() const;

		int action() const override;
};
