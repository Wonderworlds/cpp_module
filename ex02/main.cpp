/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:37:47 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/03 23:58:30 by fmauguin         ###   ########.fr       */
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

#define TEST_F(A, B)                                \
	{                                               \
		PRINT("\ntest: " << A << "\tgrade: " << B); \
		Bureaucrat a(A, B);                         \
		Form f;                                     \
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
			Form c(a);
			Form d;
			d = a;
			PRINT(a);
			PRINT(c);
			PRINT(d);
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
