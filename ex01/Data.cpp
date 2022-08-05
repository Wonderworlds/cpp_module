/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:53:39 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/05 15:15:38 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"

#ifndef __GNUC__
#pragma region Constructor && Destructor
#endif

Data::Data(void) : _value(0) {
	DEBUG_LOG("Data: Default Constructor called");
	return ;
}

Data::Data(int const &i): _value(i) {
	DEBUG_LOG("Data: Int Constructor called");
	return ;
}

Data::Data(Data const & src) {
	DEBUG_LOG("Data: Copy Constructor called");
	*this = src;

	return ;
}

Data::~Data(void) {
	DEBUG_LOG("Data: Destructor called");
	return ;
}

#ifndef __GNUC__
#pragma endregion Constructor && Destructor
#endif

int const & Data::getValue(void) const
{
	DEBUG_LOG("Data: getValue function member called");

	return this->_value;
}

Data &	Data::operator=(Data const & rhs) {
	DEBUG_LOG("Data: Assignement operator called");

	if (this != &rhs)
		this->_value = rhs.getValue();
	return *this;
}
