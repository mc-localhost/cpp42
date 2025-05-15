/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:14:59 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/19 12:59:02 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap()
{
	_name = "";
	_hit_points = 10;
	_energy_points = 10;
	_damage = 0;
	std::cout << "\e[0;33mDefault Constructor called of ClapTrap\e[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	_name = copy.getName();
	_hit_points = copy.getHit_points();
	_energy_points = copy.getEnergy_points();
	_damage = copy.getDamage();
	std::cout << "\e[0;33mCopy Constructor called of ClapTrap\e[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_hit_points = 10;
	_energy_points = 10;
	_damage = 0;
	std::cout << "\e[0;33mFields Constructor called of ClapTrap\e[0m" << std::endl;
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "\e[0;31mDestructor called of ClapTrap\e[0m" << std::endl;
}

// Operators
ClapTrap & ClapTrap::operator=(const ClapTrap &assign)
{
	if (this != &assign) {
		_name = assign.getName();
		_hit_points = assign.getHit_points();
		_energy_points = assign.getEnergy_points();
		_damage = assign.getDamage();
	}
	return *this;
}

// Getters / Setters
std::string ClapTrap::getName() const
{
	return _name;
}
unsigned int ClapTrap::getHit_points() const
{
	return _hit_points;
}
unsigned int ClapTrap::getEnergy_points() const
{
	return _energy_points;
}
unsigned int ClapTrap::getDamage() const
{
	return _damage;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		this->_energy_points -= 1;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_damage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " does not have enough energy or hit points to attack." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no hit points left." << std::endl;
		return ;
	}
	if (this->_hit_points >= amount)
	{
		this->_hit_points -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage. Hit points left: " << this->_hit_points << std::endl;
	}
	else
	{
		this->_hit_points = 0;
		std::cout << "ClapTrap " << this->_name << " takes less than " << amount << " damage but has no hit points left now." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		this->_energy_points -= 1;
		this->_hit_points += amount;
		std::cout << "ClapTrap " << this->_name << " repairs by getting " << amount << " hit points." << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " does not have enough energy points to repair." << std::endl;
}