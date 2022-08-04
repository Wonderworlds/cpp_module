/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntClass.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:00:13 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/04 17:56:38 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include "IntClass.hpp"

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

IntClass::IntClass(void) : _valueInt(0)
{
	DEBUG_LOG("IntClass: Default Constructor called");
	return;
}

IntClass::IntClass(int const &i) : _valueInt(i)
{
	DEBUG_LOG("IntClass: Int Constructor called");
	return;
}

IntClass::IntClass(float const &f)
{
	DEBUG_LOG("IntClass: Float Constructor called");
	if (f == std::numeric_limits<float>::infinity() || f == -std::numeric_limits<float>::infinity() || f == std::numeric_limits<float>::quiet_NaN())
		this->_err = "impossible";
	else if (f > std::numeric_limits<float>::max())
		this->_err = "impossible";
	else if (f < std::numeric_limits<float>::min())
		this->_err = "impossible";
	else
		this->_valueInt = static_cast<int>(f);
	return;
}

IntClass::IntClass(double const &d)
{
	DEBUG_LOG("IntClass: Double Constructor called");
	if (d == std::numeric_limits<double>::infinity() || d == -std::numeric_limits<double>::infinity() || d == std::numeric_limits<double>::quiet_NaN())
		this->_err = "impossible";
	else if (d > std::numeric_limits<float>::max())
		this->_err = "impossible";
	else if (d < std::numeric_limits<float>::min())
		this->_err = "impossible";
	else
		this->_valueInt = static_cast<int>(d);
	return;
}

IntClass::IntClass(char const &c)
{
	DEBUG_LOG("IntClass: Char Constructor called");
	this->_valueInt = static_cast<int>(c);
	return;
}

IntClass::IntClass(IntClass const &src)
{
	DEBUG_LOG("IntClass: Copy Constructor called");
	*this = src;

	return;
}

IntClass::~IntClass(void)
{
	DEBUG_LOG("IntClass: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

int const IntClass::getValue(void) const
{
	DEBUG_LOG("IntClass: getValue function member called");
	return this->_valueInt;
}

std::string const &IntClass::getErr(void) const
{
	DEBUG_LOG("IntClass: getErr function member called");

	return this->_err;
}

IntClass &IntClass::operator=(IntClass const &rhs)
{
	DEBUG_LOG("IntClass: Assignment operator called");

	if (this != &rhs)
	{
		this->_err = rhs.getErr();
		this->_valueInt = rhs.getValue();
	}
	return *this;
}
