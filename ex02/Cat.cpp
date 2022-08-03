/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:51:21 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/03 15:46:52 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

Cat::Cat(void) : AAnimal()
{
	PRINT("Cat: Default Constructor called");

	this->type = "Cat";
	this->_brain = new Brain();
	return;
}

Cat::Cat(Cat const &src) : AAnimal()
{
	PRINT("Cat: Copy Constructor called");
	this->_brain = new Brain();
	*this = src;

	return;
}

Cat::~Cat(void)
{
	PRINT("Cat: Destructor called");
	delete this->_brain;
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

Brain const *Cat::getBrain(void) const
{
	DEBUG_LOG("Cat: getBrain function member called");
	return this->_brain;
}

Cat &Cat::operator=(Cat const &rhs)
{
	DEBUG_LOG("Cat: Assignment operator called");

	if (this != &rhs)
	{
		this->type = rhs.getType();
		*this->_brain = *rhs.getBrain();
	}
	return *this;
}
