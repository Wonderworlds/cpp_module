/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:41:26 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/31 21:54:10 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void )
{
	{
		Point	a;
		const Fixed x(2);
		const Fixed y(3);
		Point	b(x, y);
		Point	c(b);

		std::cout << "\ta.x: " << a.getX() << std::endl;
		std::cout << "\ta.y: " << a.getX() << std::endl;
		std::cout << "\tb.x: " << b.getX() << std::endl;
		std::cout << "\tb.y: " << b.getY() << std::endl;
		b = a;
		std::cout << "\tb.x: " << b.getX() << std::endl;
		std::cout << "\tb.y: " << b.getY() << std::endl;
		std::cout << "\tc.x: " << c.getX() << std::endl;
		std::cout << "\tc.y: " << c.getY() << std::endl;

	}
	{
		
	}
	return (0);
}