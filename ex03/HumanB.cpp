/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:23:13 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/29 09:49:35 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
	std::cout << "Constructor called HumanB" << std::endl;
	return ;
}

HumanB::~HumanB(void) {
	std::cout << "Destructor called HumanB" << std::endl;
	return ;
}

void	HumanB::attack(void) {
	if (!this->_weapon)
		std::cout << this->_name << " attacks with nothing" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << (*this->_weapon).getType() << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	return ;
}