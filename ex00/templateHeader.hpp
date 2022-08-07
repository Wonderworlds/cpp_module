/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templateHeader.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:48:46 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/07 15:55:45 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATEHEADER_HPP
#define TEMPLATEHEADER_HPP

#include <iostream>

template <typename T>
void swap(T &v1, T &v2)
{
	T tmp = v1;

	v1 = v2;
	v2 = tmp;
}

template <typename T>
T const min(T const &v1, T v2)
{
	if (v1 > v2)
		return v2;
	return v1;
}

template <typename T>
T const max(T const &v1, T const &v2)
{
	if (v1 < v2)
		return v2;
	return v1;
}

#endif