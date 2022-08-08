/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalaireClass.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:01:31 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/08 15:08:19 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAIRECLASS_HPP
#define SCALAIRECLASS_HPP

#include <iostream>
#include "IntClass.hpp"
#include "CharClass.hpp"
#include "FloatClass.hpp"
#include "DoubleClass.hpp"

class ScalaireClass : public CharClass, public IntClass, public FloatClass, public DoubleClass
{
private:
	int _precision;

public:
	ScalaireClass(void);
	explicit ScalaireClass(int const &i, int const &p);
	explicit ScalaireClass(char const &c, int const &p);
	explicit ScalaireClass(float const &f, int const &p);
	explicit ScalaireClass(double const &d, int const &p);
	ScalaireClass(ScalaireClass const &src);
	virtual ~ScalaireClass(void);

	ScalaireClass &operator=(ScalaireClass const &rhs);
	void print(void) const;
	int const &getPrecision(void) const;
};

#endif