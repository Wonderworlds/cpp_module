/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:25:35 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/31 19:44:20 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"


#ifndef __GNUC__
#pragma region Constructor and destructor
#endif

Fixed::Fixed(void) : _value(0) {
	#ifdef DEBUG
		std::cout << "Default Constructor called" << std::endl;
	#endif
	return ;
}

Fixed::Fixed(int const newValue) : _value(newValue << _bits) {
	#ifdef DEBUG
		std::cout << "Int Constructor called" << std::endl;
	#endif
	return ;
}

Fixed::Fixed(float const newValue) : _value((int)roundf(newValue * (1 << _bits))) {
	#ifdef DEBUG
		std::cout << "Float Constructor called" << std::endl;
	#endif
	return ;
}

Fixed::Fixed(Fixed const & src) {
	#ifdef DEBUG
		std::cout << "Copy Constructor called" << std::endl;
	#endif
	*this = src;

	return ;
}

Fixed::~Fixed(void) {
	#ifdef DEBUG
		std::cout << "Destructor called" << std::endl;
	#endif
	return ;
}

#ifndef __GNUC__
#pragma endregion Constructor and destructor
#endif

#ifndef __GNUC__
#pragma region Accessor
#endif

int	Fixed::getRawBits(void) const {
	#ifdef DEBUG
		std::cout << "getRawBits member function called" << std::endl;
	#endif
	return this->_value;
}

void	Fixed::setRawBits(int const raw) {
	#ifdef DEBUG
		std::cout << "setRawBits member function called" << std::endl;
	#endif
	this->_value = raw;
	return ;
}

#ifndef __GNUC__
#pragma endregion Accessor
#endif

#ifndef __GNUC__
#pragma region convert
#endif

int	Fixed::toInt(void) const {
	#ifdef DEBUG
		std::cout << "toInt function member called" << std::endl;
	#endif
	return ((int)(roundf((float)_value / (1 << _bits))));
}

float	Fixed::toFloat(void) const {
	#ifdef DEBUG
		std::cout << "toFloat function member called" << std::endl;
	#endif
	return ((float)_value / (1 << _bits));
}
#ifndef __GNUC__
#pragma endregion
#endif

#ifndef __GNUC__
#pragma region overload_operator
#endif

Fixed &	Fixed::operator=(Fixed const & rhs) {
	#ifdef DEBUG
		std::cout << "Copy assignement operator called" << std::endl;
	#endif
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return *this;
}

Fixed	Fixed::operator+(Fixed const & rhs) const {
	#ifdef DEBUG
		std::cout << "add operator called" << std::endl;
	#endif
	Fixed	ret(*this);

	ret._value += rhs.getRawBits();
	return ret;
}

Fixed	Fixed::operator-(Fixed const & rhs) const {
	#ifdef DEBUG
		std::cout << "substract operator called" << std::endl;
	#endif
	Fixed	ret(*this);

	ret._value -= rhs.getRawBits();
	return ret;
}

Fixed	Fixed::operator*(Fixed const & rhs) const {
	#ifdef DEBUG
		std::cout << "times operator called" << std::endl;
	#endif
	Fixed	ret(this->toFloat() * rhs.toFloat());

	return ret;
}

Fixed	Fixed::operator/(Fixed const & rhs) const {
	#ifdef DEBUG
		std::cout << "division operator called" << std::endl;
	#endif
	Fixed	ret(this->toFloat() / rhs.toFloat());

	return ret;
}

Fixed &	Fixed::operator++(void) {
	#ifdef DEBUG
		std::cout << "Increment operator called" << std::endl;
	#endif
	this->_value++;
	return *this;
}

Fixed	Fixed::operator++(int) {
	#ifdef DEBUG
		std::cout << "Increment operator called" << std::endl;
	#endif
	Fixed saved(*this);
	this->_value++;
	return saved;
}

Fixed &	Fixed::operator--(void) {
	#ifdef DEBUG
		std::cout << "Increment operator called" << std::endl;
	#endif
	this->_value--;
	return *this;
}

Fixed	Fixed::operator--(int) {
	#ifdef DEBUG
		std::cout << "Increment operator called" << std::endl;
	#endif
	Fixed saved(*this);
	this->_value--;
	return saved;
}

bool	Fixed::operator>(Fixed const & rhs) const {
	#ifdef DEBUG
		std::cout << "More operator called" << std::endl;
	#endif
	if (this->_value <= rhs.getRawBits())
		return (false);
	return (true);
}

bool	Fixed::operator<(Fixed const & rhs) const {
	#ifdef DEBUG
		std::cout << "Less operator called" << std::endl;
	#endif
	if (this->_value >= rhs.getRawBits())
		return (false);
	return (true);
}

bool	Fixed::operator>=(Fixed const & rhs) const {
	#ifdef DEBUG
		std::cout << "More or equal operator called" << std::endl;
	#endif
	if (this->_value < rhs.getRawBits())
		return (false);
	return (true);
}

bool	Fixed::operator<=(Fixed const & rhs) const {
	#ifdef DEBUG
		std::cout << "Less or equal operator called" << std::endl;
	#endif
	if (this->_value > rhs.getRawBits())
		return (false);
	return (true);
}

bool	Fixed::operator==(Fixed const & rhs) const {
	#ifdef DEBUG
		std::cout << "Equal operator called" << std::endl;
	#endif
	if (this->_value != rhs.getRawBits())
		return (false);
	return (true);
}

bool	Fixed::operator!=(Fixed const & rhs) const {
	#ifdef DEBUG
		std::cout << "Not equal operator called" << std::endl;
	#endif
	if (this->_value == rhs.getRawBits())
		return (false);
	return (true);
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs) {
	#ifdef DEBUG
		std::cout << "Left flux operator called" << std::endl;
	#endif
	o << rhs.toFloat();
	return o;
}

#ifndef __GNUC__
#pragma endregion
#endif

#ifndef __GNUC__
#pragma region function member
#endif

Fixed &	Fixed::min(Fixed &f1, Fixed &f2) {
	#ifdef DEBUG
		std::cout << "min function member called" << std::endl;
	#endif
	if (f1.getRawBits() <= f2.getRawBits())
		return (f1);
	return (f2);
}

const Fixed &	Fixed::min(Fixed const &f1, Fixed const &f2) {
	#ifdef DEBUG
		std::cout << "const min function member called" << std::endl;
	#endif
	if (f1.getRawBits() <= f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed &	Fixed::max(Fixed &f1, Fixed &f2) {
	#ifdef DEBUG
		std::cout << "max function member called" << std::endl;
	#endif
	if (f1.getRawBits() >= f2.getRawBits())
		return (f1);
	return (f2);
}

const Fixed &	Fixed::max(Fixed const &f1, Fixed const &f2) {
	#ifdef DEBUG
		std::cout << "const max function member called" << std::endl;
	#endif
	if (f1.getRawBits() >= f2.getRawBits())
		return (f1);
	return (f2);
}
#ifndef __GNUC__
#pragma endregion
#endif
