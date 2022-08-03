/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:37:47 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/04 01:11:05 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define STOPC "\033[0m"

#define TITLE(A) PRINT(std::endl               \
					   << std::setw(30)        \
					   << YELLOW << A << STOPC \
					   << std::endl)

#define TEST_CREATE(F, T)                                           \
	std::cout << "\nCreation: " << std::setw(20) << #F              \
			  << " | target: " << std::setw(4) << T << " | ";       \
	try                                                             \
	{                                                               \
		F a(T);                                                     \
		std::cout << GREEN "OK" STOPC << std::endl;                 \
		PRINT(a << "\n\t| target: " << a.getTarget() << std::endl); \
	}                                                               \
	catch (std::exception & e)                                      \
	{                                                               \
		std::cout << RED << e.what() << STOPC << std::endl;         \
	}

#define TEST_F(A, B)                                \
	{                                               \
		PRINT("\ntest: " << A << "\tgrade: " << B); \
		Bureaucrat a(A, B);                         \
		AForm f;                                    \
		PRINT(f);                                   \
		a.signAForm(f);                             \
		PRINT(f);                                   \
	}

int main()
{
	{
		TITLE("CONSTRUCTOR");
		{
			PresidentialPardonForm a;
			PresidentialPardonForm b("lucky");
			PresidentialPardonForm c(a);
			PresidentialPardonForm d;
			d = b;
			PRINT(a << "\n\t| target: " << a.getTarget() << std::endl);
			PRINT(b << "\n\t| target: " << b.getTarget() << std::endl);
			PRINT(c << "\n\t| target: " << c.getTarget() << std::endl);
			PRINT(d << "\n\t| target: " << d.getTarget() << std::endl);

			TEST_CREATE(PresidentialPardonForm, "lucky")
		}
		TITLE("TESTS");
		{
		}
	}
	return (0);
}
