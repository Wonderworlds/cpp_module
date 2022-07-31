/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:55:55 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/31 23:12:57 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>


float __cross_products(Point const point, Point const A, Point const B){
	Fixed	aX(B.getX() - A.getX());
	Fixed	aY(B.getY() - A.getY());
	Fixed	pX(point.getX() - A.getX());
	Fixed	pY(point.getY() - A.getY());

	Fixed	ret = (aX*pY) - (aY*pX);
	return (ret.toFloat());
}


bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool b1, b2, b3;

	b1 = __cross_products(point, a, b) < 0.0f;
	b2 = __cross_products(point, b, c) < 0.0f;
	b3 = __cross_products(point, c, a) < 0.0f;
	return ((b1 == b2) && (b2 == b3));
}
