/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:09:12 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/04 17:59:23 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>

class Convert
{
private:
	std::string _value;

public:
	Convert(void);
	Convert(std::string const &value);
	Convert(Convert const &src);
	~Convert(void);
	void print(void) const;
	Convert &operator=(Convert const &rhs);

	std::string const &getValue() const;
};

#endif