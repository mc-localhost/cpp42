/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:12:49 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/10 15:00:53 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "max: " << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl << "MY PART" << std::endl;
	a = Fixed (0);
	std::cout << "min from a and b: " << Fixed::max( a, b ) << std::endl;
	std::cout << "b - a is " << b - a << std::endl;
	std::cout << "a * b is " << a * b << std::endl;
	// std::cout << "b / 0 is " << b / a << std::endl;
	Fixed c(20.0f);
	std::cout << "a+b+c" << a + b + c << std::endl;
	return 0;
}