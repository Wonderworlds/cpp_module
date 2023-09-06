/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:33:17 by fmauguin          #+#    #+#             */
/*   Updated: 2023/09/06 20:33:43 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
	#define DEBUG_LOG(A) PRINT(A)
#else
	#define DEBUG_LOG(A)
#endif

int	RPN::_SetRPN(std::string const &rpn) {

}

#ifndef __GNUC__
#pragma region Constructor && Destructor
#endif

RPN::RPN(void) {
	DEBUG_LOG("RPN: Default Constructor called");
	return ;
}

RPN::RPN(std::string const &rpn) {
	DEBUG_LOG("RPN: Parametric Constructor called");
	this->_SetRPN(rpn);
	return ;
}

RPN::RPN(RPN const & src) {
	DEBUG_LOG("RPN: Copy Constructor called");
	*this = src;

	return ;
}

RPN::~RPN(void) {
	DEBUG_LOG("RPN: Destructor called");
	return ;
}

#ifndef __GNUC__
#pragma endregion Constructor && Destructor
#endif


RPN &	RPN::operator=(RPN const & rhs) {
	DEBUG_LOG("RPN: Assignement operator called");

	if (this != &rhs)
		this->rpn = rhs.GetValue();
	return *this;
}

std::deque<char> const & RPN::GetValue(void) const {
	return this->rpn;
}
