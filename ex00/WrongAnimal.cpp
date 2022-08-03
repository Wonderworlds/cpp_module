/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:39:50 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/02 19:12:34 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

WrongAnimal::WrongAnimal(void)
{
	PRINT("WrongAnimal: Default Constructor called");
	return;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	PRINT("WrongAnimal: Copy Constructor called");
	*this = src;

	return;
}

WrongAnimal::~WrongAnimal(void)
{
	PRINT("WrongAnimal: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

void WrongAnimal::makeSound(void) const
{
	DEBUG_LOG("WrongAnimal: makeSound function member called");
	PRINT("WrongAnimal sound");
	return;
}

const std::string &WrongAnimal::getType(void) const
{
	DEBUG_LOG("WrongAnimal: getType function member called");
	return this->type;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
	DEBUG_LOG("WrongAnimal: Assignment operator called");

	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}
