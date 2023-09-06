/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:09:38 by fmauguin          #+#    #+#             */
/*   Updated: 2023/09/06 13:18:01 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <iostream>
#include  <fstream>


int	checkFormatFile(char *file)
{
	std::ifstream f;

	f.open(file, std::ifstream::in);
	if(std::ios::fail)
	{
		std::cout << "Error\nFile couldn't open!" << std::endl;
		return 1;
	}
	return 0;
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error\nInvalid argument!" << std::endl;
		return 1;
	}
	if (checkFormatFile(av[1]))
		return 1;
	return 0;
}