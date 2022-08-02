/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:46:35 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/02 12:18:09 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

#define TYPE "DiamondTrap: "
#define NO_HP(N) std::cout << TYPE << N << " is broken! Need repair" << std::endl
#define NO_EP(N) std::cout << TYPE << N << " has no energy" << std::endl

DiamondTrap::DiamondTrap(void) : ClapTrap("generic_clap_name"), _name("generic")
{
	PRINT("DiamondTrap: Default Constructor called");
	this->_energyPoints = 50;
	return;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name)
{
	PRINT("DiamondTrap: String Constructor called");
	this->_energyPoints = 50;
	return;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	PRINT("DiamondTrap: Copy Constructor called");
	*this = src;

	return;
}

DiamondTrap::~DiamondTrap(void)
{
	PRINT("DiamondTrap: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

void DiamondTrap::whoAmI(void)
{
	DEBUG_LOG("DiamondTrap: whoAmI function member called");

	if (this->_hitPoints == 0)
		NO_HP(this->_name);
	else if (this->_energyPoints == 0)
		NO_EP(this->_name);
	else
	{
		this->_energyPoints--;
		PRINT("I am " << this->_name << " le DiamondTrap du clan ClapTrap [ " << ClapTrap::_name << " ]");
	}
	return;
}

std::string DiamondTrap::getName(void) const
{
	DEBUG_LOG("DiamondTrap: getName function member called");

	return this->_name;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	DEBUG_LOG("DiamondTrap: Assignement operator called");

	if (this != &rhs)
	{
		this->_name = rhs.getName();
		ClapTrap::_name = this->_name + "_clap_name";
		this->_attackDamage = rhs.getAttackDamage();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
	}
	return *this;
}
