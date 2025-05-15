/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:48:31 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/03 11:35:35 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main (int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			std::string str = argv[i];
			for (auto it = str.begin(); it != str.end(); ++it)
				*it = std::toupper(*it);
			std::cout << str;
		}
	}
	std::cout << std::endl;
	return (0);
}
