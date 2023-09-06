/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:33:17 by fmauguin          #+#    #+#             */
/*   Updated: 2023/09/07 00:34:05 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
	#define DEBUG_LOG(A) PRINT(A)
#else
	#define DEBUG_LOG(A)
#endif


#ifndef __GNUC__
#pragma region Constructor && Destructor
#endif

RPN::RPN(void) {
	DEBUG_LOG("RPN: Default Constructor called");
	return ;
}

RPN::RPN(std::string const &str) : _str(str) {
	DEBUG_LOG("RPN: Parametric Constructor called");
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
		this->_str = rhs.getStr();
	return *this;
}

void RPN::setStr(std::string const &str) {
	this->_str = str;
}

std::string const &RPN::getStr(void) const {
	return this->_str;
}

int	RPN::_calculator(int n1, int n2, char op) const
{
	if (op == '+')
		return n1 + n2;
	if (op == '-')
		return n2 - n1;
	if (op == '*')
		return n1 * n2;
	if (op == '/')
	{
		if (n1 == 0)
		return n2 / n1;
	}
}

int	RPN::_resolve(void) {

	int	n1, n2;
	int result;
	std::string::const_iterator	it;

	it = _str.begin();
	while (it != _str.end())
	{
		if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
		{
			n1 = _rpn.top();
			_rpn.pop();
			n2 = _rpn.top();
			_rpn.pop();
		}
		it++
	}
}