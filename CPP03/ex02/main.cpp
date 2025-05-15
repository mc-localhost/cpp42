/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:14:55 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/24 14:01:39 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap frag = FragTrap("frag");

	std::cout << "***	FRAGTRAP CHECK	***" << std::endl;
	frag.attack("target");
	std::cout << "Frag energy points: " << frag.getEnergy_points() << std::endl;
	frag.attack("target #2");
	std::cout << "Frag energy points: " << frag.getEnergy_points() << std::endl;
	frag.beRepaired(2);
	std::cout << "Frag hit points: " << frag.getHit_points() << std::endl;
	frag.takeDamage(1);
	std::cout << "Frag hit points: " << frag.getHit_points() << std::endl;
	frag.takeDamage(100);
	std::cout << "Frag hit points: " << frag.getHit_points() << std::endl;
	frag.highFivesGuys();
	std::cout << "Frag final energy points before copying: " << frag.getEnergy_points() << std::endl;

	std::cout  << std::endl << "***	FRAGTRAP COPY CHECK	***" << std::endl;
	FragTrap frag_copy(frag);
	std::cout << "Frag copy energy points: " << frag_copy.getEnergy_points() << std::endl;
	std::cout << "Frag copy hit points: " << frag_copy.getHit_points() << std::endl;
	frag_copy.highFivesGuys();

	return 0;
}
