/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:57:25 by fmauguin          #+#    #+#             */
/*   Updated: 2023/09/07 17:48:55 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe	pme;
	if (ac < 2)
	{
		std::cout << "Error: Missing arguments." << std::endl;
		return 1;
	}
	if (pme.fillContainer(&av[1], ac - 1))
		return 1;
	pme.printOutput();
	return 0;
}