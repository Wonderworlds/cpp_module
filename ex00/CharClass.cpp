/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharClass.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:00:13 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/04 17:40:08 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include "CharClass.hpp"

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

CharClass::CharClass(void) : _valueChar(0)
{
	DEBUG_LOG("CharClass: Default Constructor called");
	return;
}

CharClass::CharClass(int const &i)
{
	DEBUG_LOG("CharClass: Int Constructor called");
	return;
}

CharClass::CharClass(float const &f)
{
	DEBUG_LOG("CharClass: Float Constructor called");
	if (f == std::numeric_limits<float>::infinity() || f == -std::numeric_limits<float>::infinity() || f == std::numeric_limits<float>::quiet_NaN())
		this->_err = "impossible";
	else if (f > INT32_MAX)
		this->_err = "impossible";
	else if (f < INT32_MIN)
		this->_err = "impossible";
	else
		this->_valueChar = static_cast<char>(f);
	return;
}

CharClass::CharClass(double const &d)
{
	DEBUG_LOG("CharClass: Double Constructor called");
	if (d == std::numeric_limits<double>::infinity() || d == -std::numeric_limits<double>::infinity() || d == std::numeric_limits<double>::quiet_NaN())
		this->_err = "impossible";
	else if (d > INT32_MAX)
		this->_err = "impossible";
	else if (d < INT32_MIN)
		this->_err = "impossible";
	else
		this->_valueChar = static_cast<int>(d);
	return;
}

CharClass::CharClass(char const &c) : _valueChar(c)
{
	DEBUG_LOG("CharClass: Char Constructor called");
	return;
}

CharClass::CharClass(CharClass const &src)
{
	DEBUG_LOG("CharClass: Copy Constructor called");
	*this = src;

	return;
}

CharClass::~CharClass(void)
{
	DEBUG_LOG("CharClass: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

int const CharClass::getValue(void) const
{
	DEBUG_LOG("CharClass: getValue function member called");
	return this->_valueChar;
}

std::string const &CharClass::getErr(void) const
{
	DEBUG_LOG("CharClass: getErr function member called");

	return this->_err;
}

CharClass &CharClass::operator=(CharClass const &rhs)
{
	DEBUG_LOG("CharClass: Assignment operator called");

	if (this != &rhs)
	{
		this->_err = rhs.getErr();
		this->_valueChar = rhs.getValue();
	}
	return *this;
}
