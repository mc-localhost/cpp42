/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:15:38 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/14 14:44:52 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Constructors
Point::Point(): _x(0), _y(0)
{
	// std::cout << "\e[0;33mDefault Constructor called of Point\e[0m" << std::endl;
}

Point::Point(const Point &copy): _x(copy._x), _y(copy._y)
{
	// std::cout << "\e[0;33mCopy Constructor called of Point\e[0m" << std::endl;
}

Point::Point(const float x, const float y): _x(x), _y(y)
{
	// std::cout << "\e[0;33mFields Constructor called of Point\e[0m" << std::endl;
}


// Destructor
Point::~Point()
{
	// std::cout << "\e[0;31mDestructor called of Point\e[0m" << std::endl;
}


// Operators
Point & Point::operator=(const Point &assign)
{
	(void)assign;
	return *this;
}


// Getters / Setters
const Fixed Point::x() const
{
	return _x;
}
const Fixed Point::y() const
{
	return _y;
}
