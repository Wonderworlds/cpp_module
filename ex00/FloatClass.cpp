/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatClass.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:00:13 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/06 17:37:22 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <climits>
#include <cmath>
#include "FloatClass.hpp"

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

FloatClass::FloatClass(void) : _valueFloat(0)
{
	DEBUG_LOG("FloatClass: Default Constructor called");
	return;
}

FloatClass::FloatClass(int const &i)
{
	DEBUG_LOG("FloatClass: Int Constructor called");

	this->_valueFloat = static_cast<float>(i);
	return;
}

FloatClass::FloatClass(float const &f) : _valueFloat(f)
{
	DEBUG_LOG("FloatClass: Float Constructor called");
	return;
}

FloatClass::FloatClass(double const &d)
{
	DEBUG_LOG("FloatClass: Double Constructor called");

	if (d == INFINITY)
		this->_valueFloat = INFINITY;
	else if (d == -INFINITY)
		this->_valueFloat = -INFINITY;
	else
	{
		if (d > __FLT_MAX__)
			this->_err = "impossible";
		else if (d < -__FLT_MAX__)
			this->_err = "impossible";
		else
			this->_valueFloat = static_cast<float>(d);
	}
	return;
}

FloatClass::FloatClass(char const &c)
{
	DEBUG_LOG("FloatClass: Char Constructor called");

	this->_valueFloat = static_cast<float>(c);
	return;
}

FloatClass::FloatClass(FloatClass const &src)
{
	DEBUG_LOG("FloatClass: Copy Constructor called");

	*this = src;
	return;
}

FloatClass::~FloatClass(void)
{
	DEBUG_LOG("FloatClass: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

float const &FloatClass::getValue(void) const
{
	DEBUG_LOG("FloatClass: getValue function member called");
	return this->_valueFloat;
}

std::string const &FloatClass::getErr(void) const
{
	DEBUG_LOG("FloatClass: getErr function member called");

	return this->_err;
}

FloatClass &FloatClass::operator=(FloatClass const &rhs)
{
	DEBUG_LOG("FloatClass: Assignment operator called");

	if (this != &rhs)
	{
		this->_err = rhs.getErr();
		this->_valueFloat = rhs.getValue();
	}
	return *this;
}
