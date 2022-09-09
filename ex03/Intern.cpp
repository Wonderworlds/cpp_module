/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:12:11 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/04 14:04:47 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

const std::string Intern::formTab[NB_FORM] = {"presidential pardon", "robotomy request", "shrubbery creation"};
AForm *(*Intern::f_make[NB_FORM])(std::string const &) = {PresidentialPardonForm::make, RobotomyRequestForm::make, ShrubberyCreationForm::make};

Intern::Intern(void)
{
	DEBUG_LOG("Intern: Default Constructor called");
	return;
}

Intern::Intern(Intern const &src)
{
	DEBUG_LOG("Intern: Copy Constructor called");
	*this = src;

	return;
}

Intern::~Intern(void)
{
	DEBUG_LOG("Intern: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

Intern &Intern::operator=(Intern const &rhs)
{
	DEBUG_LOG("Intern: Assignment operator called");

	(void)rhs;
	return *this;
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) const
{
	DEBUG_LOG("Intern: makeForm function member called");

	AForm *ret = NULL;
	unsigned int i = 0;

	while (i < NB_FORM)
	{
		if (!formName.compare(formTab[i]))
		{
			try
			{
				ret = f_make[i](target);
				PRINT("Intern creates " << ret->getName());
			}
			catch (const std::exception &e)
			{
				PRINT(e.what());
			}
			return ret;
		}
		i++;
	}
	PRINT("Intern can't find " << formName << ". Fire him !");
	return ret;
}
