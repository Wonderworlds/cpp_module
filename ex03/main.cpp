/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:41:26 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/31 19:35:02 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

#define TEST(A, B, C) std::cout << A << "\t\t" << #B << "\t" << C << "\t\t= " << (A B C) << std::endl;
#define TEST_2(A, B, C) std::cout << A << "\t\t" << #B << "\t" << C << "\t= " << B(A, C) << std::endl;

int main( void )
{
	{
		std::cout << "Mandatory" << std::endl;
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	{
		std::cout << std::endl << "Others" << std::endl;
		Fixed a(6.24f);
		Fixed b(12);
		Fixed const c(a + b);

		TEST(a, >, b)
		TEST(b, >, a)
		TEST(a, <, b)
		TEST(b, <, a)
		std::cout << std::endl;

		TEST(a, >=, b)
		TEST(c, >=, c)
		TEST(a, <=, b)
		TEST(c, <=, c)
		TEST(a, ==, b)
		TEST(c, ==, c)
		TEST(a, !=, b)
		TEST(c, !=, c)
		std::cout << std::endl;

		TEST(a, +, b)
		TEST(a, -, b)
		TEST(a, *, b)
		TEST(a, /, b)
		std::cout << std::endl;

		TEST_2(a, Fixed::min, b)
		TEST_2(a, Fixed::max, b)
	}
	return (0);
}