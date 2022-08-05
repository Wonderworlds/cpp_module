/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatClass.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:46:05 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/05 19:04:49 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOATCLASS_HPP
#define FLOATCLASS_HPP

#include <iostream>

class FloatClass
{
protected:
	float _valueFloat;
	std::string _err;

public:
	FloatClass(void);
	explicit FloatClass(int const &i);
	explicit FloatClass(float const &f);
	explicit FloatClass(double const &d);
	explicit FloatClass(char const &c);
	FloatClass(FloatClass const &src);
	virtual ~FloatClass(void);

	FloatClass &operator=(FloatClass const &rhs);

	virtual float const &getValue(void) const;
	virtual std::string const &getErr(void) const;
};

#endif