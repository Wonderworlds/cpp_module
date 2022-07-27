/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:44:25 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/27 15:02:06 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	int		i, j;
	char	c;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while (i < ac)
		{
			j = 0;
			while (av[i][j])
			{
				if (av[i][j] <= 'z' && av[i][j] >= 'a')
					c = av[i][j] - 32;
				else
					c = av[i][j];
				std::cout << c;
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}