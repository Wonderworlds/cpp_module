/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:35:56 by fmauguin          #+#    #+#             */
/*   Updated: 2023/09/07 13:41:39 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	RPN	myRPN;

	if (ac != 2)
	{
		std::cout << "Error: Invalid arguments." << std::endl;
		return 1;
	}
	else
	{
		return (myRPN.resolve(av[1]));
	}
}