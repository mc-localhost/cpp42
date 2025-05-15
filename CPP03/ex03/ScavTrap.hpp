/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:15:02 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/24 11:24:07 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap
{
	public:
		// Constructors
		ScavTrap();
		ScavTrap(std::string name);
		
		ScavTrap(const ScavTrap &copy);
		// Operators
		ScavTrap & operator=(ScavTrap assign);
		
		// Destructor
		virtual ~ScavTrap();

		void attack(const std::string& target) override;
		void guardGate() const;

};

#endif