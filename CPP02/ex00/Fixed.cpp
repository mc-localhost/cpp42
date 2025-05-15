/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:12:43 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/09 14:59:23 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors
Fixed::Fixed()
{
	_value = 0;
	std::cout << "\e[0;33mDefault Constructor called of Fixed\e[0m" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	_value = copy.getRawBits();
	std::cout << "Copy Constructor called of Fixed" << std::endl;
}

Fixed::Fixed(int value)
{
	_value = value;
	std::cout << "\e[0;33mFields Constructor called of Fixed\e[0m" << std::endl;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "\e[0;31mDestructor called of Fixed\e[0m" << std::endl;
}

// Operators
Fixed & Fixed::operator=(const Fixed &assign)
{
	if (this == &assign) return *this;
	_value = assign.getRawBits();
	std::cout << "Copy Assignment called of Fixed" << std::endl;
	return *this;
}

// Getters / Setters
int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}