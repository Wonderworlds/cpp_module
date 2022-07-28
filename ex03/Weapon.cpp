/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:49:00 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/28 17:34:12 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type) : _type(type) {
	std::cout << "Constructor called: Weapon: " << this->_type << std::endl;
	return ;
}

Weapon::Weapon(void) {
	std::cout << "Constructor called: Weapon: empty" << std::endl;
	return ;
}

Weapon::~Weapon(void) {
	if (!this->_type.empty())
		std::cout << "Destructor called: Weapon: " << this->_type << std::endl;
	else
		std::cout << "Destructor called: Weapon: empty" << std::endl;
	return ;
}

std::string	Weapon::getType(void) const {
	const std::string	&ref = this->_type;
	return (ref);
}

void	Weapon::setType(std::string type) {
	this->_type = type;
	return ;
}
