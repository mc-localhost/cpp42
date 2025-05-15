/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:15:34 by vvasiuko          #+#    #+#             */
/*   Updated: 2025/04/14 14:46:56 by vvasiuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static Fixed pseudo_scalar_product(Point const a, Point const b, Point const c)
{
	return ((b.x() - a.x()) * (c.y() - a.y()) - (c.x() - a.x()) * (b.y() - a.y()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed one = pseudo_scalar_product(point, a, b);
	Fixed two = pseudo_scalar_product(point, b, c);
	Fixed three = pseudo_scalar_product(point, c, a);

	if ((one < Fixed(0) && two < Fixed(0) && three < Fixed(0)) ||
		(one > Fixed(0) && two > Fixed(0) && three > Fixed(0)))
		return true;
	return false;
}