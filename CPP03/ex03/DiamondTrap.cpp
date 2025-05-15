/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:14:59 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/24 13:58:17 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// https://isocpp.org/wiki/faq/multiple-inheritance#mi-diamond

// • Name, which is passed as a parameter to a constructor
// • ClapTrap::name (parameter of the constructor + "_clap_name" suffix)
// • Hit points (FragTrap)
// • Energy points (ScavTrap)
// • Attack damage (FragTrap)
// • attack() (ScavTrap)

// Constructors
DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "* ADDITIONAL CONSTRUCTORS FOR ATTRIBUTE VALUES *" << std::endl;
	FragTrap frag_temp;
	ScavTrap scav_temp;
	std::cout << "* -------------------------------------------- *" << std::endl;
	_hit_points = frag_temp.getHit_points();
	_energy_points = scav_temp.getEnergy_points();
	_damage = frag_temp.getDamage();
	std::cout << "\e[0;33mDefault Constructor called of DiamondTrap\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	std::cout << "* ADDITIONAL CONSTRUCTORS FOR ATTRIBUTE VALUES *" << std::endl;
	FragTrap frag_temp;
	ScavTrap scav_temp;
	std::cout << "* -------------------------------------------- *" << std::endl;
	_name = name;
	_hit_points = frag_temp.getHit_points();
	_energy_points = scav_temp.getEnergy_points();
	_damage = frag_temp.getDamage();
	std::cout << "\e[0;33mFields Constructor called of DiamondTrap\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy._name + "_clap_name"), FragTrap(copy._name), ScavTrap(copy._name)
{
	// *this = copy;
	_name = copy._name;
	std::cout << "\e[0;33mCopy Constructor called of DiamondTrap\e[0m" << std::endl;
}

// Operators
DiamondTrap & DiamondTrap::operator=(DiamondTrap assign)
{
	// trying out smth new with copy constructor which will be called by
	// passing assign by value instead of const reference
	std::swap(_name, assign._name);
    std::swap(_hit_points, assign._hit_points);
    std::swap(_energy_points, assign._energy_points);
    std::swap(_damage, assign._damage);
	return *this;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "\e[0;31mDestructor called of DiamondTrap\e[0m" << std::endl;
}

void DiamondTrap::whoAmI() const
{
	std::cout << "Own name: " << _name << ", ClapTrap name: " << this->ClapTrap::_name << std::endl;
}

// void DiamondTrap::attack(const std::string& target)
// {
// 	ScavTrap::attack(target);
// 	std::cout << "Diamond reused attack of ScavTrap." << std::endl;
// }
