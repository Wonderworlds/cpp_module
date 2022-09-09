/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:37:47 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/04 14:45:28 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
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

#define PRINT_FORM(a) PRINT(a << "\n\t| target: " << a.getTarget() << std::endl);

#define TEST_EXEC(A, B, FORM)                       \
	std::cout << "\nExecute: " << std::setw(8) << A \
			  << " | grade: " << std::setw(3) << B  \
			  << " | form: " << #FORM               \
			  << std::endl;                         \
	A.executeForm(f);

int main()
{
	{
		{
			TITLE("MANDATORY");
			Intern someRandomIntern;
			AForm *rrf;
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			delete rrf;
		}
		{
			TITLE("CONSTRUCTOR");
			Intern a;
			Intern b(a);
			Intern c;
			c = a;
		}
		{
			TITLE("TEST scf");
			Intern a;
			Bureaucrat bb("bigBoss", 1);

			AForm *ptr = a.makeForm("shrubbery creation", "parc st Pierre");
			bb.signForm(*ptr);
			PRINT(*ptr);
			bb.executeForm(*ptr);
			delete ptr;
		}
		{
			TITLE("TEST rrf");
			Intern a;
			Bureaucrat bb("bigBoss", 1);

			AForm *ptr = a.makeForm("robotomy request", "Marvin");
			bb.signForm(*ptr);
			PRINT(*ptr);
			bb.executeForm(*ptr);
			delete ptr;
		}
		{
			TITLE("TEST ppf");
			Intern a;
			Bureaucrat bb("bigBoss", 1);

			AForm *ptr = a.makeForm("presidential pardon", "Mesrine");
			bb.signForm(*ptr);
			PRINT(*ptr);
			bb.executeForm(*ptr);
			delete ptr;
		}
		{
			TITLE("TEST fail");
			Intern a;
			Bureaucrat bb("bigBoss", 1);

			AForm *ptr = a.makeForm("presidential pardonfail", "Mesrine");
			ptr = a.makeForm("", "Mesrine");
			if (!ptr)
				PRINT("");
		}
	}
	return (0);
}
