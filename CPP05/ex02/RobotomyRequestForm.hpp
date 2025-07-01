#pragma once

#include "AForm.hpp"

#include <iostream>
#include <fstream>
#include <string>


class RobotomyRequestForm : public AForm
{
	std::string target;

	public:
		static unsigned short int const	req_sign = 72;
		static unsigned short int const	req_exec = 45;

		RobotomyRequestForm();
		RobotomyRequestForm(std::string _target);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm & operator=(const RobotomyRequestForm & assign);
		
		std::string getTarget() const;

		int action() const override;
};
