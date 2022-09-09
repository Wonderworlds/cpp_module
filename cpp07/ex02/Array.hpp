/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:45:37 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/07 18:05:11 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
private:
	T *_array;
	unsigned int _size;

	class IndexOutOfBoundsException : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};

public:
	Array<T>(void);
	Array<T>(unsigned int const &n);
	Array<T>(Array const &src);
	virtual ~Array<T>(void);

	unsigned int const &size(void) const;

	T &operator[](unsigned int const &idx) const;

	Array &operator=(Array const &rhs);
};

#include <Array.tpp>

#endif