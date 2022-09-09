/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:55:40 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/27 23:34:39 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

void	__search(PhoneBook *instance);

static void	__add(PhoneBook *instance) {
	instance->setcontact();
	std::cout << "\033[H\033[2J\033[3J";
}

static void	__menu(PhoneBook *instance) {
	std::string	buff;
	int			stop = 1;

	std::cout << "\033[H\033[2J\033[3J";
	while (stop)
	{
		std::cout << "Three choices : ADD, SEARCH, EXIT" << std::endl;
		std::cout << "Your choice: ";
		std::getline (std::cin,buff);
		std::cout << "\033[H\033[2J\033[3J";
		if (!buff.compare("EXIT"))
			stop = 0;
		else if (!buff.compare("ADD"))
			__add(instance);
		else if (!buff.compare("SEARCH"))
			__search(instance);
	}
}

int	main(void) {
	PhoneBook	instance;

	__menu(&instance);
	return (0);
}