/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:52:32 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/28 15:04:33 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << "Constructor called: " << this->_name << std::endl;
	return ;
}

Zombie::Zombie(void) {
	std::cout << "Constructor called" << std::endl;
	return ;
}

Zombie::~Zombie(void) {
	std::cout << "Destructor called: " << this->_name << std::endl;
	return ;
}

void	Zombie::announce(void) {
	std::cout << this->_name << ANNOUNCE_MSG << std::endl;
	return ;
}

void	Zombie::setname(std::string name) {
	this->_name = name;
	return ;
}
