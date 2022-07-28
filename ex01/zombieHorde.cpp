/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:29:01 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/28 15:05:26 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name ){
	Zombie	*horde = new Zombie[N];
	int		i = -1;

	while (++i < N)
		horde[i].setname(name);
	return (horde);
}