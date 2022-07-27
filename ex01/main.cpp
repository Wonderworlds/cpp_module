/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:55:40 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/27 23:12:06 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

#define PROMPT_MSG "Three choices : ADD, SEARCH, EXIT"
#define PROMPT "Your choice: "
#define BUFFER_SIZE 8

static void	__display_str(std::string str) {
	size_t	len_str;

	len_str = str.size();
	std::cout << "|";
	if (len_str <= 10)
	{
		while (len_str < 10)
		{
			std::cout << " ";
			len_str++;
		}
		std::cout << str;
	}
	else
	{
		std::cout << str.substr(0, 9);
		std::cout << ".";
	}
}

static void	__display_contact(Contact *instance, int index) {
	std::cout << "|" << "         " << index;
	__display_str(instance->getfirstname());
	__display_str(instance->getlastname());
	__display_str(instance->getnickname());
	std::cout << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

static void	__add(PhoneBook *instance) {
	instance->setcontact();
	std::cout << "\033[H\033[2J\033[3J";
}

static void	__search_index(PhoneBook *instance)
{
	std::string	number;
	Contact		*ptr;
	const int 	size = instance->getsize();

	std::cout << "Choose an index between 1 and " << size << " | 0 to return to menu";
	std::cout << std::endl << "Your choice: ";
	std::getline(std::cin, number);
	while (!(number.size() == 1 && *number.begin() <= (size + '0') && *number.begin() > '0'))
	{
		if (number.size() == 1 && *number.begin() == '0')
		{
			std::cout << "\033[H\033[2J\033[3J";
			return ;
		}
		std::cout << "\033[A\33[2K\r" << "Error index: " << number << " | Your choice: ";
		std::getline(std::cin, number);
	}
	ptr = instance->getcontact(*number.begin() - '1');
	std::cout << "\033[H\033[2J\033[3J";
	std::cout << "First name: " << ptr->getfirstname() << std::endl;
	std::cout << "Last name: " << ptr->getlastname() << std::endl;
	std::cout << "Nickname: " << ptr->getnickname() << std::endl;
	std::cout << "Phone number: " << ptr->getphonenumber() << std::endl;
	std::cout << "Darkest secret: " << ptr->getsecret() << std::endl;
	std::cout << std::endl << "Press ENTER...";
	std::cin.get();
	std::cout << "\033[H\033[2J\033[3J";
}

static void	__search(PhoneBook *instance) {
	Contact		*ptr;
	int			index = 0;
	const int	size = instance->getsize();

	std::cout << "\033[H\033[2J\033[3J";
	if (size == 0)
		std::cout << "Contact list is empty" << std::endl << std::endl;
	else
	{
		std::cout << "---------------------------------------------" << std::endl;
		while (index < size)
		{
			ptr = instance->getcontact(index);
			__display_contact(ptr, index + 1);
			index++;
		}
		__search_index(instance);
	}
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
	}
}

int	main(void) {
	PhoneBook	instance;

	__menu(&instance);
	return (0);
}