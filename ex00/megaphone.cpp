/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:44:25 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/29 09:31:34 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#define NOISE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

void	__megaphone(std::string arg)
{
	std::size_t	i = -1;

	while (arg[++i] != '\0')
		std::cout << (char)std::toupper(arg[i]);
}

int	main(int ac, char **av)
{
	std::string	str;
	int			i = 0;

	if (ac == 1)
		std::cout << NOISE << std::endl;
	else
	{
		while (av[++i])
			__megaphone(av[i]);
		std::cout << std::endl;
	}
	return (0);
}
