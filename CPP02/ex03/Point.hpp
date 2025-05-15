/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:15:42 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/10 15:36:16 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT
#define POINT
#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <string>
# include "Fixed.hpp"

class Point
{
	const Fixed _x;
	const Fixed _y;

	public:
		// Constructors
		Point();
		Point(const Point &copy);
		Point(const float x, const float y);
		
		// Destructor
		~Point();
		
		// Operators
		Point & operator=(const Point &assign);
		
		// Getters / Setters
		const Fixed x() const;
		const Fixed y() const;
		
};

#endif


#endif /* POINT */
