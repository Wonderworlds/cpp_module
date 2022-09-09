/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:25:35 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/02 09:38:32 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

#ifndef __GNUC__
#pragma region constructor && destructor
#endif

#ifdef DEBUG
#define DEBUG_LOG(A) std::cout << A << std::endl
#else
#define DEBUG_LOG(A)
#endif

Fixed::Fixed(void) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int const newValue) : _value(newValue << _bits) {
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(float const newValue) : _value((int)roundf(newValue * (1 << _bits))) {
	std::cout << "Float constructor called" << std::endl;

	return ;
}

Fixed::Fixed(Fixed const & src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

#ifndef __GNUC__
#pragma endregion constructor && destructor
#endif

int	Fixed::getRawBits(void) const {
	DEBUG_LOG("getRawBits member function called");
	return this->_value;
}

void	Fixed::setRawBits(int const raw) {
	DEBUG_LOG("setRawBits member function called");
	this->_value = raw;
	return ;
}

int	Fixed::toInt(void) const {
	return ((int)(roundf((float)_value / (1 << _bits))));
}

float	Fixed::toFloat(void) const
{
	return ((float)_value / (1 << _bits));
}

Fixed &	Fixed::operator=(Fixed const & rhs) {
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return *this;
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return o;
}
