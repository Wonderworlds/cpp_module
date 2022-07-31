/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:41:26 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/31 23:24:15 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

#define PRINT_POINT(A, B) std::cout << B << "(" << A.getX() << "; " << A.getY() << ")" << std::endl;
#define PRINT_RESULT(PT, A, B, C, F) std::cout << "is_in: " << (F(A, B, C, PT) ? "vrai" : "faux") << std::endl << std::endl;

int main( void )
{
	{
		Point	a;
		const Fixed x(2);
		const Fixed y(3);
		Point	b(x, y);
		Point	c(b);

		std::cout << std::endl << "-------------POINT CHECK-------------" <<  std::endl;
		std::cout << "a.x: " << a.getX() << std::endl;
		std::cout << "a.y: " << a.getX() << std::endl;
		std::cout << "b.x: " << b.getX() << std::endl;
		std::cout << "b.y: " << b.getY() << std::endl;
		b = a;
		std::cout << "b.x: " << b.getX() << std::endl;
		std::cout << "b.y: " << b.getY() << std::endl;
		std::cout << "c.x: " << c.getX() << std::endl;
		std::cout << "c.y: " << c.getY() << std::endl;

	}
	{
		std::cout << std::endl << "--------------BSP TESTS--------------" <<  std::endl;
		Point	a(2, 0);
		Point	b(0, 2);
		Point	c(0, 0);
		Point	pt(1, 1);
		Point	pt1(1, 1);
		Point	pt2(0.5f, 0.5f);
		Point	pt3(-0.5f, -0.5f);

		PRINT_POINT(a, "a");
		PRINT_POINT(b, "b");
		PRINT_POINT(c, "c");
		std::cout << std::endl;
		PRINT_POINT(pt, "pt");
		PRINT_RESULT(pt, a, b, c, bsp)
		PRINT_POINT(pt1, "pt1");
		PRINT_RESULT(pt1, a, b, c, bsp)
		PRINT_POINT(pt2, "pt2");
		PRINT_RESULT(pt2, a, b, c, bsp)
		PRINT_POINT(pt3, "pt3");
		PRINT_RESULT(pt3, a, b, c, bsp)
	}
	return (0);
}