/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:33:17 by fmauguin          #+#    #+#             */
/*   Updated: 2023/09/07 14:01:58 by fmauguin         ###   ########.fr       */
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
		this->_rpn = rhs.getRPN();
	return *this;
}

std::stack<int> const &RPN::getRPN(void) const {
	return this->_rpn;
}

int	RPN::_calculator(int n1, int n2, char op, bool *error)
{
	if (op == '+')
		return n2 + n1;
	if (op == '-')
		return n2 - n1;
	if (op == '*')
		return n2 * n1;
	if (op == '/')
	{
		if (n1 == 0)
		{
			PRINT("Error: Division by zero.");
			*error = true;
			return 1;
		}
		return n2 / n1;
	}
	return (0);
}

int	RPN::resolve(std::string const &str) {

	int	n1, n2;
	std::string::const_iterator	it;
	bool error = false;

	it = str.begin();
	while (it != str.end())
	{
		if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
		{
			if (_rpn.size() < 2)
			{
				PRINT("Error: RPN not valid, not enough number.");
				return 1;
			}
			n1 = _rpn.top();
			_rpn.pop();
			n2 = _rpn.top();
			_rpn.pop();
			_rpn.push(_calculator(n1, n2, *it, &error));
			if (error)
				return (1);
		}
		else if (std::isdigit(*it))
		{
			_rpn.push(*it - '0');
		}
		else if (!std::isspace(*it))
		{
			PRINT("Error: RPN not valid, not authorized character.");
			return 1;
		}
		it++;
		if (std::isspace(*it))
		{
			while (std::isspace(*it))
				it++;
		}
		else if (it == str.end())
			break ;
	}
	if (_rpn.size() > 1)
	{
		PRINT("Error: RPN not valid, not enough operation.");
		return 1;
	}
	PRINT(_rpn.top());
	return 0;
}