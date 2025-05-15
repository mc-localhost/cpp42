/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:54:13 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/03 09:54:13 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>

class HumanA
{
	public:
		// Constructors
		HumanA(std::string name, Weapon& weapon);
		
		// Destructor
		~HumanA();

		// Getters / Setters
		Weapon getWeapon() const;
		
		void attack() const;
		
	private:
		const Weapon& _weapon;
		std::string _name;
};

#endif