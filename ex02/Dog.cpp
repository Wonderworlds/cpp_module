/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:51:21 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/03 15:46:59 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

Dog::Dog(void) : AAnimal()
{
	PRINT("Dog: Default Constructor called");

	this->type = "Dog";
	this->_brain = new Brain();
	return;
}

Dog::Dog(Dog const &src) : AAnimal()
{
	PRINT("Dog: Copy Constructor called");
	this->_brain = new Brain();
	*this = src;

	return;
}

Dog::~Dog(void)
{
	PRINT("Dog: Destructor called");
	delete this->_brain;
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

Brain const *Dog::getBrain(void) const
{
	DEBUG_LOG("Cat: getBrain function member called");
	return this->_brain;
}

Dog &Dog::operator=(Dog const &rhs)
{
	DEBUG_LOG("Dog: Assignment operator called");

	if (this != &rhs)
	{
		this->type = rhs.getType();
		*this->_brain = *rhs.getBrain();
	}
	return *this;
}
