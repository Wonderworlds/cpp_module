/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntClass.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:55:00 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/04 18:35:08 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTCLASS_HPP
#define INTCLASS_HPP

#include <iostream>

class IntClass
{
protected:
	int _valueInt;
	std::string _err;

public:
	IntClass(void);
	explicit IntClass(int const &i);
	explicit IntClass(float const &f);
	explicit IntClass(double const &d);
	explicit IntClass(char const &c);
	IntClass(IntClass const &src);
	virtual ~IntClass(void);

	IntClass &operator=(IntClass const &rhs);

	virtual int getValue(void) const;
	virtual std::string const &getErr(void) const;
};

#endif