/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:09:38 by fmauguin          #+#    #+#             */
/*   Updated: 2023/09/06 22:55:14 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange btc;

	if (ac != 2)
	{
		std::cout << "\nError\nInvalid argument!" << std::endl;
		return 1;
	}
	if (btc.initDB("data.csv"))
		return 1;
	if (btc.setFile(av[1]))
		return 1;
	return 0;
}