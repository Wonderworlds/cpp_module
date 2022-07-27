/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:55:40 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/27 20:40:12 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

#define PROMPT_MSG "Three choices : ADD, SEARCH, EXIT"
#define PROMPT "Your choice: "
#define BUFFER_SIZE 8

static void	__display_contact(Contact *instance) {
	std::cout << "\033[H\033[2J\033[3J";
	std::cout << "First name: " << instance->getfirstname() << std::endl;
	std::cout << "Last name: " << instance->getlastname() << std::endl;
	std::cout << "Nickname: " << instance->getnickname() << std::endl;
	std::cout << "Phone number: " << instance->getphonenumber() << std::endl;
	std::cout << "secret: " << instance->getsecret() << std::endl;
}

static void	__add(PhoneBook *instance) {
	instance->setcontact();
	std::cout << "\033[H\033[2J\033[3J";
}

static void	__search(PhoneBook *instance) {
	Contact	*ptr;

	ptr = instance->getcontact(0);
	__display_contact(ptr);
}

static void	__menu(PhoneBook *instance) {
	std::string	buff;
	int			stop = 1;

	std::cout << "\033[H\033[2J\033[3J";
	while (stop)
	{
		std::cout << PROMPT_MSG << std::endl;
		std::cout << PROMPT;
		std::getline (std::cin,buff);
		std::cout << "\033[H\033[2J\033[3J";
		if (!buff.compare("EXIT"))
			stop = 0;
		else if (!buff.compare("ADD"))
			__add(instance);
		else if (!buff.compare("SEARCH"))
			__search(instance);
		else
			std::cout << "error: " << buff << std::endl << std::endl;
	}
}

int	main(void) {
	PhoneBook	instance;

	__menu(&instance);
	return (0);
}