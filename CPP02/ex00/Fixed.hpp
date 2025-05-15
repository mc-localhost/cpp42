/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:12:46 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/09 15:01:38 by vvasiuko         ###   ########.fr       */
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
		Fixed(int value);
		
		// Destructor
		~Fixed();
		
		// Operators
		Fixed & operator=(const Fixed &assign);
		
		// Getters / Setters
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif


#endif /* FIXED */
