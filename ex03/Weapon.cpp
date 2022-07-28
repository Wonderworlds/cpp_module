/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:49:00 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/28 15:54:24 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type) : _type(type) {
	std::cout << "Constructor called: " << this->_type << std::endl;
	return ;
}

Weapon::~Weapon(void) {
	std::cout << "Destructor called: " << this->_type << std::endl;
	return ;
}

std::string	Weapon::gettype(void) const {
	return (this->_type);
}

void	Weapon::settype(std::string type) {
	this->_type = type;
	return ;
}
