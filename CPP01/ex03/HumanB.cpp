/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:54:08 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/03 09:54:08 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

// Constructors
HumanB::HumanB()
{
	std::cout << "\e[0;33mDefault Constructor called of HumanB\e[0m" << std::endl;
}

HumanB::HumanB( std::string name)
{
	_name = name;
	std::cout << "\e[0;33mFields Constructor called of HumanB\e[0m" << std::endl;
}

// Destructor
HumanB::~HumanB()
{
	std::cout << "\e[0;31mDestructor called of HumanB\e[0m" << std::endl;
}

// Getters / Setters
Weapon* HumanB::getWeapon() const
{
	return _weapon;
}
void HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

void HumanB::attack() const
{
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}