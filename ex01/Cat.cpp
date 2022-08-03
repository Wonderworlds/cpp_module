/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:51:21 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/03 14:23:55 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

Cat::Cat(void) : Animal()
{
	PRINT("Cat: Default Constructor called");

	this->type = "Cat";
	return;
}

Cat::Cat(Cat const &src) : Animal()
{
	PRINT("Cat: Copy Constructor called");
	*this = src;

	return;
}

Cat::~Cat(void)
{
	PRINT("Cat: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

void Cat::makeSound(void) const
{
	DEBUG_LOG("Cat: makeSound function member called");
	PRINT("MIAOU! MIAOU!");
	return;
}

Cat &Cat::operator=(Cat const &rhs)
{
	DEBUG_LOG("Cat: Assignment operator called");

	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}
