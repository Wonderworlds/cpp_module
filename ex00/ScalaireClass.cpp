/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalaireClass.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:03:36 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/04 19:55:17 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "ScalaireClass.hpp"

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

ScalaireClass::ScalaireClass(void) : CharClass(), IntClass(), FloatClass(), DoubleClass()
{
	DEBUG_LOG("ScalaireClass: Default Constructor called");
	return;
}

ScalaireClass::ScalaireClass(int const &i) : CharClass(i), IntClass(i), FloatClass(i), DoubleClass(i)
{
	DEBUG_LOG("ScalaireClass: Parametric Constructor called");
	return;
}

ScalaireClass::ScalaireClass(char const &c) : CharClass(c), IntClass(c), FloatClass(c), DoubleClass(c)
{
	DEBUG_LOG("ScalaireClass: Parametric Constructor called");
	return;
}

ScalaireClass::ScalaireClass(float const &f) : CharClass(f), IntClass(f), FloatClass(f), DoubleClass(f)
{
	DEBUG_LOG("ScalaireClass: Parametric Constructor called");
	return;
}

ScalaireClass::ScalaireClass(double const &d) : CharClass(d), IntClass(d), FloatClass(d), DoubleClass(d)
{
	DEBUG_LOG("ScalaireClass: Parametric Constructor called");
	return;
}

ScalaireClass::ScalaireClass(ScalaireClass const &src) : CharClass(), IntClass(), FloatClass(), DoubleClass()
{
	DEBUG_LOG("ScalaireClass: Copy Constructor called");
	*this = src;

	return;
}

ScalaireClass::~ScalaireClass(void)
{
	DEBUG_LOG("ScalaireClass: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

#define PRINT_SCALAIRE(A, B, C, D, F) \
	if (!A.empty())                   \
		PRINT(C << A);                \
	else                              \
		PRINT(C << D << std::fixed << std::setprecision(1) << B << F << D);

void ScalaireClass::print(void) const
{
	DEBUG_LOG("ScalaireClass: print function member called");
	PRINT_SCALAIRE(CharClass::_err, this->_valueChar, "char: ", "'", "")
	PRINT_SCALAIRE(IntClass::_err, this->_valueInt, "int: ", "", "")
	PRINT_SCALAIRE(FloatClass::_err, this->_valueFloat, "float: ", "", "f")
	PRINT_SCALAIRE(DoubleClass::_err, this->_valueDouble, "double: ", "", "")
	return;
}

ScalaireClass &ScalaireClass::operator=(ScalaireClass const &rhs)
{
	DEBUG_LOG("ScalaireClass: Assignment operator called");

	if (this != &rhs)
	{
		this->_valueChar = rhs._valueChar;
		this->_valueInt = rhs._valueInt;
		this->_valueFloat = rhs._valueFloat;
		this->_valueDouble = rhs._valueDouble;
		IntClass::_err = rhs.IntClass::_err;
		CharClass::_err = rhs.CharClass::_err;
		FloatClass::_err = rhs.FloatClass::_err;
		DoubleClass::_err = rhs.DoubleClass::_err;
	}
	return *this;
}
