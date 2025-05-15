/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:15:02 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/24 11:24:15 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap
{

	public:
		// Constructors
		FragTrap();
		FragTrap(std::string name);
	
		FragTrap(const FragTrap &copy);
		// Operators
		FragTrap & operator=(FragTrap assign);
		
		// Destructor
		virtual ~FragTrap();

		void highFivesGuys() const;
		
};

#endif