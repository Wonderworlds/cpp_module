/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:47:34 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/31 21:49:49 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

#ifndef __GNUC__
#pragma region Constructor && Destructor
#endif

Point::Point(void) : _x(0), _y(0) {
	#ifdef DEBUG
		std::cout << "Default Constructor called : Point" << std::endl;
	#endif
	return ;
}

Point::Point(Fixed const & x, Fixed const & y) : _x(x), _y(y) {
	#ifdef DEBUG
		std::cout << "Parametric Constructor called" << std::endl;
	#endif
	return ;
}

Point::Point(Point const & src) {
	#ifdef DEBUG
		std::cout << "Copy Constructor called : point" << std::endl;
	#endif
	*this = src;

	return ;
}

Point::~Point(void) {
	#ifdef DEBUG
		std::cout << "Destructor called" << std::endl;
	#endif
	return ;
}

#ifndef __GNUC__
#pragma endregion Constructor && Destructor
#endif

#ifndef __GNUC__
#pragma region Function Member
#endif

Fixed const	Point::getX(void) const {
	#ifdef DEBUG
		std::cout << "Accessor getX called" << std::endl;
	#endif
	return this->_x;
}

Fixed const	Point::getY(void) const {
	#ifdef DEBUG
		std::cout << "Accessor getY called" << std::endl;
	#endif
	return this->_y;
}

Point &	Point::operator=(Point const & rhs) {
	#ifdef DEBUG
		std::cout << "Assignement operactor called" << std::endl;
	#endif
	if (this != &rhs)
	{
		(Fixed &)this->_x = rhs.getX();
		(Fixed &)this->_y = rhs.getY();
	}
	return *this;
}

#ifndef __GNUC__
#pragma endregion Function Member
#endif

