/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:01:37 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/03 16:01:47 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>

class ICharacter
{
public:
	ICharacter(void);
	ICharacter(ICharacter const &src);
	~ICharacter(void);

	ICharacter &operator=(ICharacter const &rhs);

	int getValue(void) const;
};

#endif