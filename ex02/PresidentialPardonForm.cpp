/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:13:39 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/04 00:13:48 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PresidentialPardonForm.hpp"

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

PresidentialPardonForm::PresidentialPardonForm(void) : _value(0)
{
	DEBUG_LOG("PresidentialPardonForm: Default Constructor called");
	return;
}

PresidentialPardonForm::PresidentialPardonForm(int newValue) : _value(newValue)
{
	DEBUG_LOG("PresidentialPardonForm: Parametric Constructor called");
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src)
{
	DEBUG_LOG("PresidentialPardonForm: Copy Constructor called");
	*this = src;

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

int PresidentialPardonForm::getValue(void) const
{
	return this->_value;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	DEBUG_LOG("PresidentialPardonForm: Assignment operator called");

	if (this != &rhs)
		this->_value = rhs.getValue();
	return *this;
}
