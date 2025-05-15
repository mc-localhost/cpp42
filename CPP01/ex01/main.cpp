/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:03:29 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/01 13:03:30 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
	Zombie* zomb_collective = zombieHorde(10, "just zombie");
	for (int i = 0; i < 10; ++i)
		zomb_collective[i].announce();
	delete [] zomb_collective;

	return 0;
}