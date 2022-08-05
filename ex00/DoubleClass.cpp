/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleClass.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:00:13 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/05 10:04:31 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include "DoubleClass.hpp"

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

DoubleClass::DoubleClass(void) : _valueDouble(0)
{
	DEBUG_LOG("DoubleClass: Default Constructor called");
	return;
}

DoubleClass::DoubleClass(int const &i)
{
	DEBUG_LOG("DoubleClass: Int Constructor called");

	this->_valueDouble = static_cast<double>(i);
	return;
}

DoubleClass::DoubleClass(float const &f)
{
	DEBUG_LOG("DoubleClass: Float Constructor called");

	if (f == std::numeric_limits<float>::infinity())
		this->_valueDouble = std::numeric_limits<double>::infinity();
	else if (f == -std::numeric_limits<float>::infinity())
		this->_valueDouble = -std::numeric_limits<double>::infinity();
	else if (f == std::numeric_limits<float>::quiet_NaN())
		this->_valueDouble = std::numeric_limits<double>::quiet_NaN();
	else
		this->_valueDouble = static_cast<double>(f);
	return;
}

DoubleClass::DoubleClass(double const &d) : _valueDouble(d)
{
	DEBUG_LOG("DoubleClass: Double Constructor called");
	return;
}

DoubleClass::DoubleClass(char const &c)
{
	DEBUG_LOG("DoubleClass: Char Constructor called");

	this->_valueDouble = static_cast<double>(c);
	return;
}

DoubleClass::DoubleClass(DoubleClass const &src)
{
	DEBUG_LOG("DoubleClass: Copy Constructor called");

	*this = src;
	return;
}

DoubleClass::~DoubleClass(void)
{
	DEBUG_LOG("DoubleClass: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

double DoubleClass::getValue(void) const
{
	DEBUG_LOG("DoubleClass: getValue function member called");
	return this->_valueDouble;
}

std::string const &DoubleClass::getErr(void) const
{
	DEBUG_LOG("DoubleClass: getErr function member called");

	return this->_err;
}

DoubleClass &DoubleClass::operator=(DoubleClass const &rhs)
{
	DEBUG_LOG("DoubleClass: Assignment operator called");

	if (this != &rhs)
	{
		this->_err = rhs.getErr();
		this->_valueDouble = rhs.getValue();
	}
	return *this;
}
