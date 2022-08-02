/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:51:21 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/02 19:14:26 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

Cat::Cat(void) : Animal()
{
	DEBUG_LOG("Cat: Default Constructor called");

	this->type = "Cat";
	return;
}

Cat::Cat(Cat const &src) : Animal()
{
	DEBUG_LOG("Cat: Copy Constructor called");
	*this = src;

	return;
}

Cat::~Cat(void)
{
	DEBUG_LOG("Cat: Destructor called");
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
	DEBUG_LOG("Cat: Assignement operator called");

	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}
