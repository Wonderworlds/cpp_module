/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:12:34 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/03 16:21:30 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

Ice::Ice(void) : AMateria("ice")
{
	DEBUG_LOG("Ice: Default Constructor called");
	return;
}

Ice::Ice(Ice const &src) : AMateria()
{
	DEBUG_LOG("Ice: Copy Constructor called");
	*this = src;

	return;
}

Ice::~Ice(void)
{
	DEBUG_LOG("Ice: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

void Ice::use(ICharacter &target)
{
	DEBUG_LOG("Ice: use function member called");
	PRINT("* shoots an ice bolt at <target> *");
	return;
}

AMateria *Ice::clone(void) const
{
	DEBUG_LOG("Ice: clone function member called");
	AMateria *ret = new Ice();

	return (ret);
}

Ice &Ice::operator=(Ice const &rhs)
{
	DEBUG_LOG("Ice: Assignement operator called");

	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}
