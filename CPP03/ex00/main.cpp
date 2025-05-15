/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:14:55 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/19 11:35:49 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap = ClapTrap("clap");

	std::cout << "***	CLAPTRAP CHECK	***" << std::endl;
	clap.attack("target");
	std::cout << "Clap energy points: " << clap.getEnergy_points() << std::endl;
	clap.attack("target #2");
	std::cout << "Clap energy points: " << clap.getEnergy_points() << std::endl;
	clap.beRepaired(2);
	std::cout << "Clap hit points: " << clap.getHit_points() << std::endl;
	clap.takeDamage(1);
	std::cout << "Clap hit points: " << clap.getHit_points() << std::endl;
	clap.takeDamage(100);
	std::cout << "Clap hit points: " << clap.getHit_points() << std::endl;

	return 0;
}
