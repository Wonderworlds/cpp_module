/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharClass.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:00:13 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/05 10:03:54 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include <cmath>
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

	if (i > std::numeric_limits<char>::max() || i < std::numeric_limits<char>::min())
		this->_err = "impossible";
	else
	{
		if (i < 32 || i == 127)
			this->_err = "not displayable";
		this->_valueChar = static_cast<char>(i);
	}
	return;
}

CharClass::CharClass(float const &f)
{
	DEBUG_LOG("CharClass: Float Constructor called");
	float checkNan = f;

	if (f == std::numeric_limits<float>::infinity() || f == -std::numeric_limits<float>::infinity() || checkNan != f)
		this->_err = "impossible";
	else if (f > std::numeric_limits<char>::max() || f < std::numeric_limits<char>::min())
		this->_err = "impossible";
	else
	{
		if (f < 32 || f == 127)
			this->_err = "not displayable";
		this->_valueChar = static_cast<char>(f);
	}
	return;
}

CharClass::CharClass(double const &d)
{
	DEBUG_LOG("CharClass: Double Constructor called");
	double checkNan = d;

	if (d == std::numeric_limits<double>::infinity() || d == -std::numeric_limits<double>::infinity() || checkNan != d)
		this->_err = "impossible";
	else if (d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min())
		this->_err = "impossible";
	else
	{
		if (d < 32 || d == 127)
			this->_err = "not displayable";
		this->_valueChar = static_cast<char>(d);
	}
	return;
}

CharClass::CharClass(char const &c) : _valueChar(c)
{
	DEBUG_LOG("CharClass: Char Constructor called");

	if (c < 32 || c == 127)
		this->_err = "not displayable";
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

char CharClass::getValue(void) const
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
