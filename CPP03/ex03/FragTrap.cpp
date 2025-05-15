/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:14:59 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/24 14:00:45 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap() : ClapTrap()
{
	_hit_points = 100;
	_energy_points = 100;
	_damage = 30;
	std::cout << "\e[0;33mDefault Constructor called of FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 100;
	_damage = 30;
	std::cout << "\e[0;33mFields Constructor called of FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "\e[0;33mCopy Constructor called of FragTrap\e[0m" << std::endl;
}

// Operators
FragTrap & FragTrap::operator=(FragTrap assign)
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
FragTrap::~FragTrap()
{
	std::cout << "\e[0;31mDestructor called of FragTrap\e[0m" << std::endl;
}

void FragTrap::highFivesGuys() const
{
	std::cout << "FragTrap " << this->_name << " is asking for a high-five." << std::endl;
}