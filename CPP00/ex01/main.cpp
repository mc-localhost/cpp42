/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:57:56 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/03 12:05:52 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

static std::string trim_whitespace(std::string &input)
{
	auto begin = input.find_first_not_of(" \t\v\r\f");
	if (begin == std::string::npos) //the whole string is whitespace
		return ("");
	auto end = input.find_last_not_of(" \t\v\r\f");
	return (input.substr(begin, end - begin + 1));
}

static void	ask_for_input(std::string &input, std::string prompt)
{
	input.clear();
	while (input.empty())
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			exit(0);
		}
		input = trim_whitespace(input);
	}
}

static void	search(PhoneBook& book)
{
	std::string index;

	if (book.get_last_i() > 0) //means that contacts' list was modified at some point
	{
		book.print_contacts();
		ask_for_input(index, "\nEnter index between 0 and 7 to get full info: ");
		try {
			int int_index = std::stoi(index, nullptr, 10);
			book.search_contact(int_index);
		}
		catch (const std::invalid_argument& e){
			std::cerr << "Invalid input: " << e.what() << std::endl;
		}
		catch (const std::out_of_range& e){
			std::cerr << "Invalid input: " << e.what() << std::endl;
		}
	}
	else
		std::cout << "The phonebook is empty" << std::endl;
}

int	main()
{
	PhoneBook book = PhoneBook();
	std::string input, f_name, l_name, nick, number, secret;

	ask_for_input(input, "Enter ADD, SEARCH or EXIT: ");
	while (input != "EXIT")
	{
		if (input == "ADD")
		{
			ask_for_input(f_name, "Enter first name: ");
			ask_for_input(l_name, "Enter last name: ");
			ask_for_input(nick, "Enter nickname: ");
			ask_for_input(number, "Enter phone number: ");
			ask_for_input(secret, "Enter darkest secret: ");
			try
			{
				Contact c(f_name, l_name, nick, number, secret);
				book.add_contact(c);
				std::cout << "*** CONTACT ADDED! ***" << std::endl;
			}
			catch (const std::invalid_argument& e)
			{
				std::cerr << "Error creating contact: " << e.what() << std::endl;
			}
		}
		else if (input == "SEARCH")
			search(book);
		else
			std::cerr << "Invalid command. Try again with ADD, SEARCH or EXIT" << std::endl;
		ask_for_input(input, "\nEnter ADD, SEARCH or EXIT: ");
	}
	return (0);
}
