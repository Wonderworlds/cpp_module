/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 21:48:33 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/28 22:06:29 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

void	err_arg(void)
{
	std::cerr << "error: invalid arg" << std::endl;
	return ;
}

void	__harl(const char **cmd)
{
	std::string	buffer;
	Harl	instance;
	int		i = 0;

	while (cmd[i])
	{
		buffer = cmd[i];
		std::cout << "level: " << buffer << std::endl;
		std::cout << "Harl: ";
		instance.complain(buffer);
		std::cout << std::endl;
		i++;
	}
}

int	main(int ac, const char **av)
{
	if (ac < 2)
		return (err_arg(), 1);
	__harl(&av[1]);
	return (0);
}