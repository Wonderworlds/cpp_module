/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:45:47 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/28 14:20:15 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

int	main(void)
{
	Zombie	*ptr;

	ptr = newZombie("serge");
	ptr->announce();
	randomChump("rand_john");
	delete(ptr);
	return (0);
}
