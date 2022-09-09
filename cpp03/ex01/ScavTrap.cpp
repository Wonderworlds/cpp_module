/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:58:08 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/01 18:24:49 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

#define TYPE "ScavTrap: "
#define ATTACK(N, T, D) std::cout << TYPE << N << " attacks " << T << ", causing " << D << " points of damage!" << std::endl
#define GUARD(N) std::cout << TYPE << N << " takes a guardian stance! Beware!" << std::endl
#define NO_HP(N) std::cout << TYPE << N << " is broken! Need repair" << std::endl
#define NO_EP(N) std::cout << TYPE << N << " has no energy" << std::endl

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

ScavTrap::ScavTrap(void) : ClapTrap()
{
	PRINT("ScavTrap: Default Constructor called");
	this->_attackDamage = 20;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	return;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	PRINT("ScavTrap: String Constructor called");
	this->_attackDamage = 20;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	return;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	PRINT("ScavTrap: Copy Constructor called");
	*this = src;

	return;
}

ScavTrap::~ScavTrap(void)
{
	PRINT("ScavTrap: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

#ifndef __GNUC__
#pragma region function members
#endif

void ScavTrap::attack(const std::string &target)
{
	DEBUG_LOG("ScavTrap: attack function member called");

	if (this->_hitPoints == 0)
		NO_HP(this->_name);
	else if (this->_energyPoints == 0)
		NO_EP(this->_name);
	else
	{
		this->_energyPoints--;
		ATTACK(this->_name, target, this->_attackDamage);
	}
	return;
}

void ScavTrap::guardGate(void)
{
	DEBUG_LOG("ScavTrap: guardgate function member called");

	if (this->_hitPoints == 0)
		NO_HP(this->_name);
	else if (this->_energyPoints == 0)
		NO_EP(this->_name);
	else
	{
		this->_energyPoints--;
		GUARD(this->_name);
	}
	return;
}

#ifndef __GNUC__
#pragma endregion function members
#endif

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	DEBUG_LOG("ScavTrap: Assignement operator called");
	if (this != &rhs)
	{
		this->_attackDamage = rhs.getAttackDamage();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
	}
	return *this;
}
