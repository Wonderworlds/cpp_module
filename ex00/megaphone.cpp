/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:44:25 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/27 16:46:48 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	__megaphone(char *line)
{
	int		j;
	char	c;

	j = 0;
	while (line[j])
	{
		if (line[j] <= 'z' && line[j] >= 'a')
			c = line[j] - 32;
		else
			c = line[j];
		std::cout << c;
		j++;
	}
}

int	main(int ac, char **av)
{
	int		i;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while (i < ac)
		{
			__megaphone(av[i]);
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}