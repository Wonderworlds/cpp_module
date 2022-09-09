/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:12:34 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/03 16:18:36 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

Cure::Cure(void) : AMateria("cure")
{
	DEBUG_LOG("Cure: Default Constructor called");
	return;
}

Cure::Cure(Cure const &src) : AMateria()
{
	DEBUG_LOG("Cure: Copy Constructor called");
	*this = src;

	return;
}

Cure::~Cure(void)
{
	DEBUG_LOG("Cure: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

void Cure::use(ICharacter &target)
{
	DEBUG_LOG("Cure: use function member called");
	PRINT("* heals " << target.getName() << "'s wounds *");
	return;
}

AMateria *Cure::clone(void) const
{
	DEBUG_LOG("Cure: clone function member called");
	AMateria *ret = new Cure();

	return (ret);
}

Cure &Cure::operator=(Cure const &rhs)
{
	DEBUG_LOG("Cure: Assignement operator called");

	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}
