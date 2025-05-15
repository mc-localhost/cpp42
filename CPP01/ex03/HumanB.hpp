/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:54:04 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/03 09:54:05 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>

class HumanB
{
	public:
		// Constructors
		HumanB();
		HumanB(std::string name);
		
		// Destructor
		~HumanB();
		
		// Getters / Setters
		Weapon* getWeapon() const;
		void setWeapon(Weapon& weapon);
		
		void attack() const;

	private:
		Weapon* _weapon;
		std::string _name;
};

#endif