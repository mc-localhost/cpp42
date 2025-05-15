/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:14:59 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/24 14:00:09 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap() : ClapTrap()
{
	_hit_points = 100;
	_energy_points = 50;
	_damage = 20;
	std::cout << "\e[0;33mDefault Constructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 50;
	_damage = 20;
	std::cout << "\e[0;33mFields Constructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "\e[0;33mCopy Constructor called of ScavTrap\e[0m" << std::endl;
}

// Operators
ScavTrap & ScavTrap::operator=(ScavTrap assign)
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
ScavTrap::~ScavTrap()
{
	std::cout << "\e[0;31mDestructor called of ScavTrap\e[0m" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		this->_energy_points -= 1;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << this->_damage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " does not have enough energy or hit points to attack." << std::endl;
}

void ScavTrap::guardGate() const
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}