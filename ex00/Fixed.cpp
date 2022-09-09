/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:25:35 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/02 09:34:19 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
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

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
	return ;
}

Fixed &	Fixed::operator=(Fixed const & rhs) {
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return *this;
}
