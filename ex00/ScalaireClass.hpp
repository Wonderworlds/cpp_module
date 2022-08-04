/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalaireClass.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:01:31 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/04 18:07:49 by fmauguin         ###   ########.fr       */
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
public:
	ScalaireClass(void);
	explicit ScalaireClass(int const &i);
	explicit ScalaireClass(char const &c);
	explicit ScalaireClass(float const &f);
	explicit ScalaireClass(double const &d);
	ScalaireClass(ScalaireClass const &src);
	~ScalaireClass(void);

	ScalaireClass &operator=(ScalaireClass const &rhs);
	void print(void) const;
};

#endif