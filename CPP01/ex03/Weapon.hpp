/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:53:57 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/03 09:53:58 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
	public:
		// Constructors
		Weapon();
		Weapon(std::string type);
		
		// Destructor
		~Weapon();
		
		// Getters / Setters
		const std::string& getType() const;
		void setType(std::string type);
		
	private:
		std::string _type;
		
};

#endif