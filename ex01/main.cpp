/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:28:12 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/28 15:17:24 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <limits.h>

#define N_LIMIT 10000

Zombie* zombieHorde(int N, std::string name);

void	error_arg(void)
{
	std::cerr << "error: invalid argument" << std::endl;
	return ;
}

int	check_arg(const char *s, int *ret)
{
	size_t		it;
	long long	n;

	n = 0;
	if (!s)
		return (1);
	it = 0;
	while (s[it] && s[it] <= '9' && s[it] >= '0')
	{
		n *= 10;
		n += s[it] - '0';
		if (n > N_LIMIT)
			return (1);
		it++;
	}
	if (s[it] || n == 0)
		return (1);
	*ret = (int)n;
	return (0);
}


int	main(int ac, const char **av)
{
	int		n;
	int		i;
	Zombie	*ptr;

	if (ac != 3 && ac != 1)
		return (error_arg(), 1);
	if (ac == 1)
	{
		ptr = zombieHorde(10, "razrockets");
		n = 10;
	}
	else
	{
		if (check_arg(av[1], &n) == 1)
			return (error_arg(), 1);
		ptr = zombieHorde(n, av[2]);
	}
	i = -1;
	while (++i < n)
		ptr[i].announce();
	delete[] ptr;
	return (0);
}
