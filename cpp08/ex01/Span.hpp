/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 21:48:12 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/10 10:01:40 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>

class Span
{
private:
	unsigned int _sizeMax;
	std::list<int> _numbers;

	class NotEnoughNumbersStoredException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class MaxSizeReachedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

public:
	Span(void);
	Span(unsigned int const &N);
	Span(Span const &src);
	~Span(void);

	Span &operator=(Span const &rhs);

	unsigned int const &getSizeMax(void) const;
	void addNumber(int const &toAdd);
	int shortestSpan() const;
	int longestSpan() const;
	std::list<int> const &getList() const;
	void fillList(std::list<int>::iterator first, std::list<int>::iterator last);
	void fillList(std::deque<int>::iterator first, std::deque<int>::iterator last);
	void fillList(std::vector<int>::iterator first, std::vector<int>::iterator last);
};

#endif