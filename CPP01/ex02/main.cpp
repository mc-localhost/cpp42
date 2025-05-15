/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:03:29 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/01 13:03:30 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	//	A string variable initialized to "HI THIS IS BRAIN".
	std::string str = "HI THIS IS BRAIN";
	//	stringPTR: a pointer to the string.
	std::string* stringPTR = &str;
	//	stringREF: a reference to the string.
	std::string& stringREF = str;

	std::cout << "The memory address of the string variable." << std::endl;
	std::cout << &str << std::endl;
	std::cout << "The memory address held by stringPTR." << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF" << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << "The value of the string variable." << std::endl;
	std::cout << str << std::endl;
	std::cout << "The value pointed to by stringPTR." << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF." << std::endl;
	std::cout << stringREF << std::endl;
	
	return 0;
}