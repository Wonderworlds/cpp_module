/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:57:35 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/08 16:05:14 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename S>
void iter(T *tab, S size, void (*fct)(T &))
{
	S index = 0;
	while (index < size)
	{
		(*fct)(tab[index]);
		index++;
	}
}

template <typename T>
void print(T &toPrint)
{
	std::cout << toPrint << "\t";
}

#endif