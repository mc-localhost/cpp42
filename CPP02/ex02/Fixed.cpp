/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:12:43 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/14 14:51:29 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// Constructors
Fixed::Fixed()
{
	_value = 0;
	std::cout << "\e[0;33mDefault Constructor called of Fixed\e[0m" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	_value = copy.getRawBits();
	// std::cout << "Copy Constructor called of Fixed" << std::endl;
}

Fixed::Fixed(const int value)
{
	_value = value << _bits;
	std::cout << "\e[0;33mFields Constructor called of Fixed\e[0m" << std::endl;
}

Fixed::Fixed(const float value)
{
	_value = static_cast<int>(roundf(value * (1 << _bits)));
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
	// std::cout << "Copy Assignment called of Fixed" << std::endl;
	return *this;
}

//other operators
bool Fixed::operator<(const Fixed &assign) const
{
	return (_value < assign._value);
}

bool Fixed::operator>(const Fixed &assign) const
{
	return (_value > assign._value);
}

bool Fixed::operator>=(const Fixed &assign) const
{
	return (_value >= assign._value);
}

bool Fixed::operator<=(const Fixed &assign) const
{
	return (_value <= assign._value);
}

bool Fixed::operator==(const Fixed &assign) const
{
	return (_value == assign._value);
}

bool Fixed::operator!=(const Fixed &assign) const
{
	return (_value != assign._value);
}

Fixed& Fixed::operator++() //prefix
{
	_value += 1;
	return *this;
}

Fixed Fixed::operator++(int) //postfix
{
	Fixed res(*this);
	_value += 1;
	return res;
}

Fixed& Fixed::operator--() //prefix
{
	_value -= 1;
	return *this;
}

Fixed Fixed::operator--(int) //postfix
{
	Fixed res(*this);
	_value -= 1;
	return res;
}

//arithmetic
Fixed Fixed::operator+(const Fixed&a) const
{
	// Fixed res(a.toFloat() + b.toFloat());
	Fixed res;
	res.setRawBits(_value + a._value);
	return res;
}

Fixed Fixed::operator-(const Fixed&a) const
{
	// Fixed res(a.toFloat() - b.toFloat());
	Fixed res;
	res.setRawBits(_value - a._value);
	return res;
}

Fixed Fixed::operator*(const Fixed&a) const
{
	// Fixed res(a.toFloat() * b.toFloat());
	Fixed res;
	res.setRawBits((_value * a._value) >> _bits);
	return res;
}

Fixed Fixed::operator/(const Fixed&a) const
{
	// Fixed res(a.toFloat() / b.toFloat());
	Fixed res;
	res.setRawBits((_value << _bits) / a._value);
	return res;
}

// Getters / Setters
int Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float Fixed::toFloat( void ) const
{
	return static_cast<float>(1.f * _value / (1 << _bits));
}

int Fixed::toInt( void ) const
{
	return (_value >> _bits);
}

//min-max
Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return ((a < b) ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return ((a > b) ? a : b);
}

//<<

std::ostream & operator<<(std::ostream &os, const Fixed &num)
{ 
    return os << num.toFloat();
}