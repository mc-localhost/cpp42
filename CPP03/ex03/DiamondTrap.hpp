/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:15:02 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/24 11:18:56 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
	private:
		std::string _name;

	public:
		// Constructors
		DiamondTrap();
		DiamondTrap(std::string name);

		DiamondTrap(const DiamondTrap &copy);
		// Operators
		DiamondTrap & operator=(DiamondTrap assign);

		// Destructor
		virtual ~DiamondTrap();

		// void attack(const std::string& target) override;
		// using ScavTrap::attack;
		void whoAmI() const;
};

#endif