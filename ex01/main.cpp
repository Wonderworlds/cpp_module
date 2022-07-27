/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:55:40 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/27 18:35:03 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

#define PROMPT_MSG "three choices : ADD, SEARCH, EXIT"
#define PROMPT "Your choice: "
#define BUFFER_SIZE 8

int	main(void)
{
	std::string	buff;

	std::cout << PROMPT_MSG << std::endl;
	std::cout << PROMPT;
	std::getline (std::cin,buff);
	std::cout << PROMPT << "[" << buff << "]" << std::endl;

	return (0);
}