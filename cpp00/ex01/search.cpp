/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:20:37 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/27 23:32:35 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

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

static void	__search_index(PhoneBook *instance)
{
	std::string		number;
	const Contact	*ptr;
	const int 		size = instance->getsize();

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

static void	__print_contacts(PhoneBook *instance, const int size)
{
	int				index = 0;
	const Contact	*ptr;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     index| firstname|  lastname|  nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	while (index < size)
	{
		ptr = instance->getcontact(index);
		std::cout << "|" << "         " << index + 1;
		__display_str(ptr->getfirstname());
		__display_str(ptr->getlastname());
		__display_str(ptr->getnickname());
		std::cout << "|" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		index++;
	}
}

void	__search(PhoneBook *instance) {
	const int	size = instance->getsize();

	std::cout << "\033[H\033[2J\033[3J";
	if (size == 0)
		std::cout << "Contact list is empty" << std::endl << std::endl;
	else
	{
		__print_contacts(instance, size);
		__search_index(instance);
	}
}
