/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:53:52 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/03 09:53:53 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Constructors
Weapon::Weapon()
{
	_type = "";
	std::cout << "\e[0;33mDefault Constructor called of Weapon\e[0m" << std::endl;
}

Weapon::Weapon(std::string type)
{
	_type = type;
	std::cout << "\e[0;33mFields Constructor called of Weapon\e[0m" << std::endl;
}

// Destructor
Weapon::~Weapon()
{
	std::cout << "\e[0;31mDestructor called of Weapon\e[0m" << std::endl;
}

// Getters / Setters
const std::string& Weapon::getType() const
{
	return _type;
}
void Weapon::setType(std::string type)
{
	_type = type;
}

