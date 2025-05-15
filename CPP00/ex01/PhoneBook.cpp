/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:40:26 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/03 12:16:36 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : last_i(0) {}

int	PhoneBook::get_last_i()
{
	return (last_i);
}

void PhoneBook::add_contact(Contact contact)
{
	contacts[last_i] = contact;
	last_i = (last_i + 1) % SIZE;
}

std::string PhoneBook::trunc_member(const std::string str) const
{
	if (str.length() > WIDTH)
		return (str.substr(0, WIDTH - 1) + ".");
	return (str);
}

void PhoneBook::print_header() const
{
	std::cout << std::endl << std::setw(WIDTH) << "Index" << " |"
	<< std::setw(WIDTH) << "First Name" << " |"
	<< std::setw(WIDTH) << "Last Name" << " |"
	<< std::setw(WIDTH) << "Nickname" << " |" << std::endl;

	std::cout << std::string((WIDTH + 2) * 4, '-') << std::endl;
}

void	PhoneBook::print_contacts() const
{
	print_header();
	for (int i = 0; i < SIZE; i++) //not to create another last_i var
	{
		if (!contacts[i].get_f_name().empty())
		{
			std::cout << std::setw(WIDTH) << i << " |"
			<< std::setw(WIDTH) << trunc_member(contacts[i].get_f_name()) << " |"
			<< std::setw(WIDTH) << trunc_member(contacts[i].get_l_name()) << " |"
			<< std::setw(WIDTH) << trunc_member(contacts[i].get_nick()) << " |" << std::endl;
		}
	}
}

void PhoneBook::search_contact(int index)
{
	if ((index < 0) || (index >= SIZE))
	{
		std::cerr << "Incorrect index. Try again with SEARCH" << std::endl;
		return ;
	}
	if (!contacts[index].get_f_name().empty())
	{ 
		std::cout << "First Name: " << contacts[index].get_f_name() << std::endl
		<< "Last Name: " << contacts[index].get_l_name() << std::endl
		<< "Nickname: " << contacts[index].get_nick() << std::endl
		<< "Phone Number: " << contacts[index].get_number() << std::endl
		<< "Darkest Secret: " << contacts[index].get_secret() << std::endl;
	}
	else
		std::cerr << "No contact for this index. Try again with SEARCH" << std::endl;
}
