/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:25:35 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/31 16:46:13 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {
	std::cout << "Default Constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int const newValue) : _value(newValue << _bits) {
	std::cout << "Int Constructor called" << std::endl;
	return ;
}

Fixed::Fixed(float const newValue) : _value((int)roundf(newValue * (1 << _bits))) {
	std::cout << "Float Constructor called" << std::endl;

	return ;
}

Fixed::Fixed(Fixed const & src) {
	std::cout << "Copy Constructor called" << std::endl;
	*this = src;

	return ;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
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
	std::cout << "Copy assignement operator called" << std::endl;

	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return *this;
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return o;
}
