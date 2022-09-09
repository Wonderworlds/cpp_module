/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:39:50 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/03 15:45:43 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

AAnimal::AAnimal(void)
{
	PRINT("AAnimal: Default Constructor called");
	return;
}

AAnimal::AAnimal(AAnimal const &src)
{
	PRINT("AAnimal: Copy Constructor called");
	*this = src;

	return;
}

AAnimal::~AAnimal(void)
{
	PRINT("AAnimal: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

const std::string &AAnimal::getType(void) const
{
	DEBUG_LOG("AAnimal: getType function member called");
	return this->type;
}

AAnimal &AAnimal::operator=(AAnimal const &rhs)
{
	DEBUG_LOG("AAnimal: Assignment operator called");

	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}
