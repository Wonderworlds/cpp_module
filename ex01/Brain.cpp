/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:30:04 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/03 14:49:53 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

Brain::Brain(void)
{
	PRINT("Brain: Default Constructor called");
	return;
}

Brain::Brain(Brain const &src)
{
	PRINT("Brain: Copy Constructor called");
	*this = src;

	return;
}

Brain::~Brain(void)
{
	PRINT("Brain: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

std::string const *Brain::getIdeas(void) const
{
	DEBUG_LOG("Brain: getIdeas function member");
	return this->ideas;
}

Brain &Brain::operator=(Brain const &rhs)
{
	int i;
	std::string const *rhsIdeas;
	DEBUG_LOG("Brain: Assignement operator called");

	if (this != &rhs)
	{
		rhsIdeas = rhs.getIdeas();
		i = -1;
		while (++i < 100)
			this->ideas[i] = rhsIdeas[i];
	}
	return *this;
}
