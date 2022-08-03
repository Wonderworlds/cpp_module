/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:37:47 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/03 22:56:56 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Bureaucrat.hpp"

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define STOPC "\033[0m"

#define TITLE(A) PRINT(std::endl               \
					   << std::setw(30)        \
					   << YELLOW << A << STOPC \
					   << std::endl)

#define TEST_CREATE(A, B)                                       \
	std::cout << "\ntest: " << A << "\tgrade: " << B << "\t| "; \
	try                                                         \
	{                                                           \
		Bureaucrat a(A, B);                                     \
		std::cout << GREEN "OK" STOPC << std::endl;             \
	}                                                           \
	catch (std::exception & e)                                  \
	{                                                           \
		std::cout << RED << e.what() << STOPC << std::endl;     \
	}

#define TEST_F(A, B, F)                                              \
	PRINT("\ntest: " << A << "\tgrade: " << B << "\tfunction: " #F); \
	try                                                              \
	{                                                                \
		Bureaucrat a(A, B);                                          \
		std::cout << a << "\t| ";                                    \
		a.F;                                                         \
		std::cout << GREEN "OK" STOPC " |\t";                        \
		std::cout << a << std::endl;                                 \
	}                                                                \
	catch (std::exception & e)                                       \
	{                                                                \
		std::cout << RED << e.what() << STOPC << std::endl;          \
	}

int main()
{
	{
		TITLE("CONSTRUCTOR");
		{
			Bureaucrat a;
			Bureaucrat b("cadre", 10);
			Bureaucrat c(b);
			Bureaucrat d;
			d = b;
			PRINT(a);
			PRINT(b);
			PRINT(c);
			PRINT(d);
		}
		TITLE("TESTS");
		{
			TEST_CREATE("esclave", 150)
			TEST_CREATE("cadre", 10)
			TEST_CREATE("BIG BOSS", 1)
			TEST_CREATE("GASTON", 155)
			TEST_CREATE("DIEU", 0)
			TEST_CREATE("DEVIL", -666)
			TITLE("FUNCTION");
			TEST_F("cadre", 10, promote())
			TEST_F("cadre", 10, demote())
			TEST_F("esclave", 150, promote())
			TEST_F("esclave", 150, demote())
			TEST_F("BIG BOSS", 1, promote());
			TEST_F("BIG BOSS", 1, demote());
		}
	}
	return (0);
}
