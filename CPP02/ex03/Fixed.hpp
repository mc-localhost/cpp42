/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:12:46 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/10 14:54:45 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED
#define FIXED
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	int _value;
	static const int _bits = 8;

	public:
		// Constructors
		Fixed();
		Fixed(const Fixed &copy);
		Fixed(const int value);
		Fixed(const float value);
		
		// Destructor
		~Fixed();
		
		// Operators
		Fixed & operator=(const Fixed &assign);

		//	comparison
		bool operator>(const Fixed &assign) const;
		bool operator<(const Fixed &assign) const;
		bool operator>=(const Fixed &assign) const;
		bool operator<=(const Fixed &assign) const;
		bool operator==(const Fixed &assign) const;
		bool operator!=(const Fixed &assign) const;
		
		//	increment/decrement
		Fixed& operator++(); //prefix
		Fixed operator++(int); //postfix
		Fixed& operator--(); //prefix
		Fixed operator--(int); //postfix
		// //	arithmetic
		Fixed operator+(const Fixed &a) const;
		Fixed operator-(const Fixed &a) const;
		Fixed operator*(const Fixed &a) const;
		Fixed operator/(const Fixed &a) const;

		// Getters / Setters
		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;
		
		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);
	};

std::ostream & operator<<(std::ostream &os, const Fixed &num);

#endif


#endif /* FIXED */
