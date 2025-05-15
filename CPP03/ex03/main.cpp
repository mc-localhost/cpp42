/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:14:55 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/24 14:02:22 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap dia("dia");

	std::cout << "***	DIAMOND CHECK	***" << std::endl;
	std::cout << "Diamond must attack with 30 damage points and Scav message," << std::endl;
	std::cout << "initial num of hit points must be 100, energy - 50." << std::endl << std::endl;
	std::cout << "dia initial hit points: " << dia.getHit_points() << std::endl;
	std::cout << "dia initial energy points: " << dia.getEnergy_points() << std::endl;
	std::cout << "dia damage: " << dia.getDamage() << std::endl << std::endl;

	dia.attack("target");
	std::cout << "dia energy points: " << dia.getEnergy_points() << std::endl;
	dia.beRepaired(2);
	std::cout << "dia hit points: " << dia.getHit_points() << std::endl;
	dia.takeDamage(100);
	std::cout << "dia hit points: " << dia.getHit_points() << std::endl;
	dia.whoAmI();
	dia.guardGate();
	dia.highFivesGuys();
	std::cout << "dia final energy points before copying: " << dia.getEnergy_points() << std::endl;

	std::cout << std::endl << "***	DIAMONDTRAP COPY CHECK	***" << std::endl;
	DiamondTrap dia_copy(dia);
	std::cout << "dia copy energy points: " << dia_copy.getEnergy_points() << std::endl;
	std::cout << "dia copy hit points: " << dia_copy.getHit_points() << std::endl;
	dia_copy.whoAmI();

	return 0;
}
