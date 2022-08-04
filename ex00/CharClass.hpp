/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharClass.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:36:34 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/04 17:37:38 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARCLASS_HPP
#define CHARCLASS_HPP

#include <iostream>

class CharClass
{
protected:
	char _valueChar;
	std::string _err;

public:
	CharClass(void);
	explicit CharClass(int const &i);
	explicit CharClass(float const &f);
	explicit CharClass(double const &d);
	explicit CharClass(char const &c);
	CharClass(CharClass const &src);
	virtual ~CharClass(void);

	CharClass &operator=(CharClass const &rhs);

	int const getValue(void) const;
	std::string const &getErr(void) const;
};

#endif