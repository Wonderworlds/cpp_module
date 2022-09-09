/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:39:50 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/03 14:24:48 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

Animal::Animal(void)
{
	PRINT("Animal: Default Constructor called");
	return;
}

Animal::Animal(Animal const &src)
{
	PRINT("Animal: Copy Constructor called");
	*this = src;

	return;
}

Animal::~Animal(void)
{
	PRINT("Animal: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

void Animal::makeSound(void) const
{
	DEBUG_LOG("Animal: makeSound function member called");
	PRINT("Animal sound");
	return;
}

const std::string &Animal::getType(void) const
{
	DEBUG_LOG("Animal: getType function member called");
	return this->type;
}

Animal &Animal::operator=(Animal const &rhs)
{
	DEBUG_LOG("Animal: Assignment operator called");

	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}
