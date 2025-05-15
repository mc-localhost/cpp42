/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:03:51 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/01 13:32:04 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	std::string _name;

	public:
		Zombie();
		Zombie(std::string name);

		~Zombie();
		
		std::string getName() const;
		void setName(std::string name);
		void announce();
	};

#endif