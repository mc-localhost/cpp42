/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:54:10 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/03 09:54:11 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

// Constructors

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon)
{
	_name = name;
	std::cout << "\e[0;33mFields Constructor called of HumanA\e[0m" << std::endl;
}

// Destructor
HumanA::~HumanA()
{
	std::cout << "\e[0;31mDestructor called of HumanA\e[0m" << std::endl;
}

// Getters / Setters
Weapon HumanA::getWeapon() const
{
	return _weapon;
}

void HumanA::attack() const
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
