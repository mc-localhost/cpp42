/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:24:50 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/03 11:23:46 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK
#define PHONEBOOK

#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <string>

class PhoneBook
{
	public:
		static constexpr int SIZE = 8;
		static constexpr int WIDTH = 10;
	
	private:
		Contact contacts[SIZE];
		int	last_i;

		std::string trunc_member(const std::string str) const; //needs access to WIDTH, only used to print contacts
		void print_header() const; //needs access to WIDTH, only used to print contacts

	public:
		PhoneBook();
		int	get_last_i();
		void print_contacts() const;
		void add_contact(Contact contact);
		void search_contact(int index);
};

#endif /* PHONEBOOK */
