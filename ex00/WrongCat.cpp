/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:51:21 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/02 19:23:04 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

WrongCat::WrongCat(void) : WrongAnimal()
{
	DEBUG_LOG("WrongCat: Default Constructor called");

	this->type = "WrongCat";
	return;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal()
{
	DEBUG_LOG("WrongCat: Copy Constructor called");
	*this = src;

	return;
}

WrongCat::~WrongCat(void)
{
	DEBUG_LOG("WrongCat: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

void WrongCat::makeSound(void) const
{
	DEBUG_LOG("WrongCat: makeSound function member called");
	PRINT("MIAOU! MIAOU!");
	return;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
	DEBUG_LOG("WrongCat: Assignement operator called");

	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}
