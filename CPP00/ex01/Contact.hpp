/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:24:46 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/03 11:13:34 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT
#define CONTACT

#include <iostream>
#include <string>

class Contact
{
	std::string first_name, last_name, nickname, number, secret;

    bool is_valid_num(const std::string& number) const;

	public:
		Contact();
		Contact(std::string first_name, std::string last_name, std::string nickname,
			std::string number, std::string secret);
		std::string get_f_name() const;
		std::string get_l_name() const;
		std::string get_nick() const;
		std::string get_number() const;
		std::string get_secret() const;
};

#endif /* CONTACT */
