/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleClass.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:46:05 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/05 19:04:16 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLECLASS_HPP
#define DOUBLECLASS_HPP

#include <iostream>

class DoubleClass
{
protected:
	double _valueDouble;
	std::string _err;

public:
	DoubleClass(void);
	explicit DoubleClass(int const &i);
	explicit DoubleClass(float const &f);
	explicit DoubleClass(double const &d);
	explicit DoubleClass(char const &c);
	DoubleClass(DoubleClass const &src);
	virtual ~DoubleClass(void);

	DoubleClass &operator=(DoubleClass const &rhs);

	virtual double const &getValue(void) const;
	virtual std::string const &getErr(void) const;
};

#endif