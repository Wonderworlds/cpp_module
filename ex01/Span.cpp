/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 21:59:19 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/07 23:22:37 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Span.hpp>

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

Span::Span(void) : _sizeMax(0)
{
	DEBUG_LOG("Span: Default Constructor called");
	return;
}

Span::Span(unsigned int const &N) : _sizeMax(N)
{
	DEBUG_LOG("Span: Parametric Constructor called");
	return;
}

Span::Span(Span const &src)
{
	DEBUG_LOG("Span: Copy Constructor called");
	*this = src;

	return;
}

Span::~Span(void)
{
	DEBUG_LOG("Span: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

unsigned int const &Span::getSizeMax(void) const
{
	DEBUG_LOG("Span: getSizeMax function member called");
	return this->_sizeMax;
}

std::list<int> const &Span::getList(void) const
{
	DEBUG_LOG("Span: getLst function member called");

	return this->_numbers;
}

void Span::addNumber(int const &toAdd)
{
	DEBUG_LOG("Span: addNumber function member called");

	if (this->_numbers.size() >= this->_sizeMax)
		throw MaxSizeReachedException();
	this->_numbers.push_back(toAdd);
	return;
}

int Span::shortestSpan(void) const
{
	DEBUG_LOG("Span: shortestSpan function member called");

	if (this->_numbers.size() < 2)
		throw NotEnoughNumbersStoredException();
	std::list<int> tmp = this->_numbers;
	tmp.sort();
	std::list<int>::iterator i = tmp.begin();
	std::list<int>::iterator prev = i++;
	int ret = *i - *prev;
	while (i != --tmp.end())
	{
		prev = i++;
		if (*i - *prev < ret)
			ret = *i - *prev;
	}
	return ret;
}

int Span::longestSpan(void) const
{
	DEBUG_LOG("Span: shortestSpan function member called");

	int ret = 0;

	if (this->_numbers.size() < 2)
		throw NotEnoughNumbersStoredException();
	std::list<int> tmp = this->_numbers;
	tmp.sort();
	ret = (*(--tmp.end()) - *(tmp.begin()));
	return ret;
}
Span &Span::operator=(Span const &rhs)
{
	DEBUG_LOG("Span: Assignment operator called");

	if (this != &rhs)
	{
		this->_sizeMax = rhs.getSizeMax();
		this->_numbers.clear();
		this->_numbers = rhs.getList();
	}
	return *this;
}

const char *Span::NotEnoughNumbersStoredException::what() const throw()
{
	return ("Need more elements in list");
}

const char *Span::MaxSizeReachedException::what() const throw()
{
	return ("list full");
}
