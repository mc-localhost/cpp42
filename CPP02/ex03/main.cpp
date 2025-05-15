/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:12:49 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/14 15:03:21 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point a(0.f, 0.f);
	Point b(4.5f, 0.f);
	Point c(2.2f, 3.f);

	Point point_in(2.5f, 1.f);
	Point point_out(-5.f, -8.f);
	Point point_on(2.f, 0.f);
	
	std::cout << "Point inside: (should be 1) " << bsp(a, b, c, point_in) << std::endl;
	std::cout << "Point inside: (should be 0) " << bsp(a, b, c, point_out) << std::endl;
	std::cout << "Point inside: (should be 0) " << bsp(a, b, c, point_on) << std::endl;
	return 0;
}