/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:51:21 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/02 19:20:58 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

Dog::Dog(void) : Animal()
{
	DEBUG_LOG("Dog: Default Constructor called");

	this->type = "Dog";
	return;
}

Dog::Dog(Dog const &src) : Animal()
{
	DEBUG_LOG("Dog: Copy Constructor called");
	*this = src;

	return;
}

Dog::~Dog(void)
{
	DEBUG_LOG("Dog: Destructor called");
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
	DEBUG_LOG("Dog: Assignement operator called");

	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}
