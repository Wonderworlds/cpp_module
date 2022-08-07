/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:13:39 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/07 20:24:43 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("empty")
{
	DEBUG_LOG("PresidentialPardonForm: Default Constructor called");
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	DEBUG_LOG("PresidentialPardonForm: Parametric Constructor called");
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src), _target(src.getTarget())
{
	DEBUG_LOG("PresidentialPardonForm: Copy Constructor called");

	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	DEBUG_LOG("PresidentialPardonForm: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

std::string const &PresidentialPardonForm::getTarget(void) const
{
	DEBUG_LOG("PresidentialPardonForm: getTarget function member called");
	return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	DEBUG_LOG("PresidentialPardonForm: execute function member called");

	if (executor.getGrade() > this->getGradeToExe())
		throw GradeTooLowException();
	if (!this->getIsSigned())
		throw FormNotSignedException();
	PRINT(this->_target << ", You are therefore pardonned by Zaphod Beeblebrox");
	return;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	DEBUG_LOG("PresidentialPardonForm: Assignment operator called");

	(void)rhs;
	return *this;
}

AForm *PresidentialPardonForm::make(std::string const &target)
{
	DEBUG_LOG("PresidentialPardonForm: make function non member called");
	PresidentialPardonForm *ptr = new (std::nothrow) PresidentialPardonForm(target);

	if (!ptr)
		throw Intern::NoPapersException();
	return ptr;
}
