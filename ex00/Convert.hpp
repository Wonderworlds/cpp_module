/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:09:12 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/04 16:54:14 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>

class Convert
{
private:
	std::string _value;
	int *_i;
	char *_c;
	float *_f;
	double *_d;
	void convertInt();
	void convertFloat();
	void convertDouble();
	void convertChar();

public:
	Convert(void);
	Convert(std::string const &value);
	Convert(Convert const &src);
	~Convert(void);
	void print(void) const;
	Convert &operator=(Convert const &rhs);

	std::string const &getValue() const;
	int const *getI() const;
	char const *getC() const;
	float const *getF() const;
	double const *getD() const;
};

#endif