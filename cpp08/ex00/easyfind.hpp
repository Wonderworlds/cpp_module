/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:43:42 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/07 21:01:17 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

template <typename T>
typename T::iterator easyfind(T hay, int needle)
{
	typename T::iterator it;

	it = find(hay.begin(), hay.end(), needle);
	if (it == hay.end())
		throw std::out_of_range("int not found");
	return (it);
}

#endif