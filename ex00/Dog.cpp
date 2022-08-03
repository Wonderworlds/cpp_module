/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
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

Dog::Dog(void) : Animal()
{
	PRINT("Dog: Default Constructor called");

	this->type = "Dog";
	return;
}

Dog::Dog(Dog const &src) : Animal()
{
	PRINT("Dog: Copy Constructor called");
	*this = src;

	return;
}

Dog::~Dog(void)
{
	PRINT("Dog: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

void Dog::makeSound(void) const
{
	DEBUG_LOG("Dog: makeSound function member called");
	PRINT("WOUAF! WOUAF!");
	return;
}

Dog &Dog::operator=(Dog const &rhs)
{
	DEBUG_LOG("Dog: Assignment operator called");

	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}
