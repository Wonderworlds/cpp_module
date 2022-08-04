/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:24:38 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/04 18:00:37 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Convert.hpp"

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

Convert::Convert(void) : _value("empty")
{
	DEBUG_LOG("Convert: Default Constructor called");
	return;
}

Convert::Convert(std::string const &value) : _value(value)
{
	DEBUG_LOG("Convert: String Constructor called");
	return;
}

Convert::Convert(Convert const &src)
{
	DEBUG_LOG("Convert: Copy Constructor called");
	*this = src;

	return;
}

Convert::~Convert(void)
{
	DEBUG_LOG("Convert: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

std::string const &Convert::getValue(void) const
{
	DEBUG_LOG("Convert: getValue function member called");

	return this->_value;
}

Convert &Convert::operator=(Convert const &rhs)
{
	DEBUG_LOG("Convert: Assignment operator called");

	if (this != &rhs)
		this->_value = rhs.getValue();
	return *this;
}
