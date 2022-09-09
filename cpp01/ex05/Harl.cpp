/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 21:26:44 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/28 22:14:43 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl(void) {
	std::cout << "Contructor called: Harl" << std::endl;
	this->_f[0] = &Harl::debug;
	this->_f[1] = &Harl::info;
	this->_f[2] = &Harl::warning;
	this->_f[3] = &Harl::error;
	return ;
}

Harl::~Harl(void) {
	std::cout << "Destructor called: Harl" << std::endl;
	return ;
}

void	Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.";
	std::cout << std::endl << "I really do!" << std::endl;
	return ;
}

void	Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << std::endl << "You didn’t put enough bacon in my burger!";
	std::cout << std::endl << "If you did, I wouldn’t be asking for more!" << std::endl;
	return ;
}

void	Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
	return ;
}

void	Harl::error(void) {
	std::cout << "This is unacceptable!" << std::endl;
	std::cout << "I want to speak to the manager now." << std::endl;
	return ;
}

void	Harl::complain(std::string level) {
	const char	*levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i;

	i = 0;
	while (i < 4)
	{
		if (level.compare(levels[i]) == 0)
		{
			(this->*(_f[i]))();
			return ;
		}
		i++;
	}
	return ;
}