/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:24:38 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/04 17:56:27 by fmauguin         ###   ########.fr       */
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

Convert::Convert(void) : _value("empty"), _i(0), _c(0), _f(0), _d(0)
{
	DEBUG_LOG("Convert: Default Constructor called");
	return;
}

Convert::Convert(std::string const &value) : _value(value), _i(0), _c(0), _f(0), _d(0)
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

#ifndef __GNUC__
#pragma region Accessors
#endif

std::string const &Convert::getValue(void) const
{
	DEBUG_LOG("Convert: getValue function member called");

	return this->_value;
}

int const *Convert::getI(void) const
{
	DEBUG_LOG("Convert: getI function member called");

	return this->_i;
}

float const *Convert::getF(void) const
{
	DEBUG_LOG("Convert: getF function member called");

	return this->_f;
}

double const *Convert::getD(void) const
{
	DEBUG_LOG("Convert: getD function member called");

	return this->_d;
}

char const *Convert::getC(void) const
{
	DEBUG_LOG("Convert: getC function member called");

	return this->_c;
}

#ifndef __GNUC__
#pragma endregion Accessors
#endif

#ifndef __GNUC__
#pragma region Function member
#endif

void Convert::convertInt(void)
{
	DEBUG_LOG("Convert: convertInt function member called");

	return;
}

void Convert::print(void) const
{
	DEBUG_LOG("Convert: print function member called");

	if (this->_c && *this->_c >= 32 && *this->_c < 127)
		PRINT("char: '" << this->_c << "'");
	else if (this->_c)
		PRINT("char: non displayable");
	else
		PRINT("char: impossible");
	if (this->_i)
		PRINT("int: " << this->_c);
	else
		PRINT("int: impossible");
	if (this->_f)
		PRINT("float: " << this->_f << "f");
	else
		PRINT("float: impossible");
	if (this->_d)
		PRINT("double: " << this->_d);
	else
		PRINT("double: impossible");
	return;
}

#ifndef __GNUC__
#pragma endregion Function member
#endif

#define COPY(src, dest) \
	if (!src && dest)   \
	{                   \
		delete dest;    \
		dest = NULL;    \
	}                   \
	else                \
		*dest = *src;

Convert &Convert::operator=(Convert const &rhs)
{
	DEBUG_LOG("Convert: Assignment operator called");

	if (this != &rhs)
	{
		this->_value = rhs.getValue();
		COPY(rhs.getC(), this->_c)
		COPY(rhs.getI(), this->_i)
		COPY(rhs.getD(), this->_d)
		COPY(rhs.getF(), this->_f)
	}
	return *this;
}
