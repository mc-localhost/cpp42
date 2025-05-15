/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:52:41 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/03 11:35:40 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

bool Contact::is_valid_num(const std::string& number) const
{
	for (char c : number)
	{
		if (!std::isdigit(c))
			return (false);
	}
	if (number.length() > 15)
		return (false);
	return (!number.empty());
}

Contact::Contact(){}

Contact::Contact(std::string first_name, std::string last_name, std::string nickname,
	std::string number, std::string secret)
{
	if (!is_valid_num(number))
		throw std::invalid_argument("invalid phone number\n   Sorry, number must contain ONLY digits and be no longer than 15 digits");
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->number = number;
	this->secret = secret;
}

std::string Contact::get_f_name() const
{
	return (first_name);
}

std::string Contact::get_l_name() const
{
	return (last_name);
}

std::string Contact::get_nick() const
{
	return (nickname);
}

std::string Contact::get_number() const
{
	return (number);
}

std::string Contact::get_secret() const
{
	return (secret);
}
