/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:14:55 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/24 14:03:58 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "***	SCAVTRAP CHECK	***" << std::endl;
	ScavTrap scav("scav");
	scav.attack("target");
	std::cout << "Scav energy points: " << scav.getEnergy_points() << std::endl;
	scav.attack("target #2");
	std::cout << "Scav energy points: " << scav.getEnergy_points() << std::endl;
	scav.beRepaired(2);
	std::cout << "Scav hit points: " << scav.getHit_points() << std::endl;
	scav.takeDamage(1);
	std::cout << "Scav hit points: " << scav.getHit_points() << std::endl;
	scav.takeDamage(100);
	std::cout << "Scav hit points: " << scav.getHit_points() << std::endl;
	scav.guardGate();
	std::cout << "Scav energy points before copying: " << scav.getEnergy_points() << std::endl;
	std::cout << "Scav hit points before copying: " << scav.getHit_points() << std::endl;

	std::cout << std::endl << "***	SCAVTRAP ASSIGNMENT COPY CHECK	***" << std::endl;
	ScavTrap scav_ass = scav;
	scav_ass.attack("another target");
	std::cout << "Scav ass copy energy points (should have lost 1 point after attack): " << scav_ass.getEnergy_points() << std::endl;
	std::cout << "Scav ass copy hit points: " << scav_ass.getHit_points() << std::endl;
	
	std::cout << std::endl << "***	SCAVTRAP COPY CHECK	***" << std::endl;
	ScavTrap scav_copy(scav);
	scav_copy.attack("copy target");
	std::cout << "Scav copy energy points (should have lost 1 point after attack): " << scav_copy.getEnergy_points() << std::endl;
	std::cout << "Scav copy hit points: " << scav_copy.getHit_points() << std::endl;

	return 0;
}
