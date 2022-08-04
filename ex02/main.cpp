/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:37:47 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/04 03:13:59 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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

#define TEST_SIGN(A, B, FORM, T)                                    \
	{                                                               \
		std::cout << "\nSign: " << std::setw(8) << A                \
				  << " | grade: " << std::setw(3) << B              \
				  << " | form: " << #FORM                           \
				  << std::endl;                                     \
		Bureaucrat a(A, B);                                         \
		FORM f(T);                                                  \
		PRINT(f << "\n\t| target: " << f.getTarget() << std::endl); \
		a.signForm(f);                                              \
	}

#define TEST_EXEC(A, B, FORM, T, S)                                 \
	{                                                               \
		std::cout << "\nExecute: " << std::setw(8) << A             \
				  << " | grade: " << std::setw(3) << B              \
				  << " | form: " << #FORM                           \
				  << "| signed: " << ((S) ? "true" : "false")       \
				  << std::endl;                                     \
		Bureaucrat a(A, B);                                         \
		FORM f(T);                                                  \
		if (S)                                                      \
			a.signForm(f);                                          \
		PRINT(f << "\n\t| target: " << f.getTarget() << std::endl); \
		a.executeForm(f);                                           \
	}

int main()
{
	{
		{
			TITLE("CONSTRUCTOR ppf");
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
			TITLE("Sign & exec ppf");
			TEST_SIGN("darmanain", 26, PresidentialPardonForm, "unlucky")
			TEST_SIGN("BIG BOSS", 1, PresidentialPardonForm, "lucky")
			TEST_EXEC("Prime minister", 6, PresidentialPardonForm, "unlucky", 1)
			TEST_EXEC("BIG BOSS", 1, PresidentialPardonForm, "lucky", 1)
			TEST_EXEC("BIG BOSS", 1, PresidentialPardonForm, "unlucky", 0)
		}
		TITLE("CONSTRUCTOR rrf");
		{
			RobotomyRequestForm a;
			RobotomyRequestForm b("unlucky");
			RobotomyRequestForm c(a);
			RobotomyRequestForm d;
			d = b;
			PRINT(a << "\n\t| target: " << a.getTarget() << std::endl);
			PRINT(b << "\n\t| target: " << b.getTarget() << std::endl);
			PRINT(c << "\n\t| target: " << c.getTarget() << std::endl);
			PRINT(d << "\n\t| target: " << d.getTarget() << std::endl);

			TITLE("Sign & exec ppf");
			TEST_CREATE(RobotomyRequestForm, "unlucky")
			TEST_CREATE(RobotomyRequestForm, "lucky")
			TEST_SIGN("darmanain", 73, RobotomyRequestForm, "unlucky")
			TEST_SIGN("BIG BOSS", 1, RobotomyRequestForm, "lucky")
			TEST_EXEC("Prime minister", 6, RobotomyRequestForm, "unlucky", 1)
			TEST_EXEC("BIG BOSS", 1, RobotomyRequestForm, "unlucky", 0)
			TEST_EXEC("BIG BOSS", 1, RobotomyRequestForm, "lucky", 1)
			TITLE("exec rand");
			std::srand(std::time(NULL));
			Bureaucrat bb("BIG BOSS", 1);
			PRINT("");
			bb.signForm(b);
			for (size_t i = 0; i < 10; i++)
			{
				PRINT("");
				bb.executeForm(b);
			}
		}
		TITLE("CONSTRUCTOR scf");
		{
			ShrubberyCreationForm a;
			ShrubberyCreationForm b("unlucky");
			ShrubberyCreationForm c(a);
			ShrubberyCreationForm d;
			d = b;
			PRINT(a << "\n\t| target: " << a.getTarget() << std::endl);
			PRINT(b << "\n\t| target: " << b.getTarget() << std::endl);
			PRINT(c << "\n\t| target: " << c.getTarget() << std::endl);
			PRINT(d << "\n\t| target: " << d.getTarget() << std::endl);

			TITLE("Sign & exec scf");
			TEST_CREATE(ShrubberyCreationForm, "unlucky")
			TEST_CREATE(ShrubberyCreationForm, "lucky")
			TEST_SIGN("darmanain", 73, ShrubberyCreationForm, "unlucky")
			TEST_SIGN("BIG BOSS", 1, ShrubberyCreationForm, "lucky")
			TEST_EXEC("Prime minister", 6, ShrubberyCreationForm, "unlucky", 1)
			TEST_EXEC("BIG BOSS", 1, ShrubberyCreationForm, "unlucky", 0)
			TEST_EXEC("BIG BOSS", 1, ShrubberyCreationForm, "lucky", 1)
			TITLE("exec");
			std::srand(std::time(NULL));
			Bureaucrat bb("BIG BOSS", 1);
			PRINT("");
			bb.signForm(b);
			for (size_t i = 0; i < 3; i++)
			{
				PRINT("");
				bb.executeForm(b);
			}
		}
	}
	return (0);
}
