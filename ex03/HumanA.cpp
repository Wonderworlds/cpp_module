/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:55:39 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/28 16:06:02 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon) : _name(name), _weapon(weapon) {
	std::cout << "Constructor called HumanA" << std::endl;
	return ;
}

HumanA::~HumanA(void) {
	std::cout << "Destructor called HumanA" << std::endl;
	return ;
}

void	HumanA::attack(void) {
	return ;
}