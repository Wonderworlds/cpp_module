/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:03:34 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/03 17:18:45 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

AMateria::AMateria(void)
{
	DEBUG_LOG("AMateria: Default Constructor called");
	return;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	DEBUG_LOG("AMateria: String Constructor called");
	return;
}

AMateria::AMateria(AMateria const &src)
{
	DEBUG_LOG("AMateria: Copy Constructor called");
	*this = src;

	return;
}

AMateria::~AMateria(void)
{
	DEBUG_LOG("AMateria: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

std::string const &AMateria::getType(void) const
{
	DEBUG_LOG("AMateria: getType function member called");
	return this->_type;
}

void AMateria::use(ICharacter &target)
{
	DEBUG_LOG("AMateria: use function member called");
	PRINT("*use Materia at " << target.getName());
	return;
}

AMateria &AMateria::operator=(AMateria const &rhs)
{
	DEBUG_LOG("AMateria: Assignement operator called");

	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}
