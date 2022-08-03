/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:37:47 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/04 00:30:01 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Bureaucrat.hpp"
#include "Form.hpp"

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define STOPC "\033[0m"

#define TITLE(A) PRINT(std::endl               \
					   << std::setw(30)        \
					   << YELLOW << A << STOPC \
					   << std::endl)
#define TEST_CREATE(A, B, C)                                                                                                     \
	std::cout << "\ntest: " << A << "\t| gradeToSign: " << std::setw(4) << B << " | gradetoExe: " << std::setw(4) << C << " | "; \
	try                                                                                                                          \
	{                                                                                                                            \
		Form a(A, B, C);                                                                                                         \
		std::cout << GREEN "OK" STOPC << std::endl;                                                                              \
	}                                                                                                                            \
	catch (std::exception & e)                                                                                                   \
	{                                                                                                                            \
		std::cout << RED << e.what() << STOPC << std::endl;                                                                      \
	}

#define TEST_F(A, B)                                \
	{                                               \
		PRINT("\ntest: " << A << "\tgrade: " << B); \
		Bureaucrat a(A, B);                         \
		Form f("laissez passer A38", 10, 1);        \
		PRINT(f);                                   \
		a.signForm(f);                              \
		PRINT(f);                                   \
	}

int main()
{
	{
		TITLE("CONSTRUCTOR");
		{
			Form a;
			Form b("laissez passer A38", 10, 1);
			Form c(a);
			Form d;
			d = b;
			PRINT(a);
			PRINT(b);
			PRINT(c);
			PRINT(d);

			TEST_CREATE("f1\t", 1, 1)
			TEST_CREATE("f2\t", 10, 16)
			TEST_CREATE("err sign too high", 0, 1)
			TEST_CREATE("err exe too high", 1, 0)
			TEST_CREATE("err sign too Low", 151, 150)
			TEST_CREATE("err exe too Low", 150, 151)
		}
		TITLE("TESTS");
		{
			TEST_F("cadre", 10)
			PRINT("");
			TEST_F("BIG BOSS", 1)
		}
	}
	return (0);
}
