/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:06:08 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/01 19:20:22 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

#define TYPE "ClapTrap: "
#define ATTACK(N, T, D) std::cout << TYPE << N << " attacks " << T << ", causing " << D << " points of damage!" << std::endl
#define HIT(N, D) std::cout << TYPE << N << " takes " << D << " points of damage!" << std::endl
#define REPAIR(N, D) std::cout << TYPE << N << " is repaired for " << D << " hit points!" << std::endl
#define NO_HP(N) std::cout << TYPE << N << " is broken! Need repair" << std::endl
#define NO_EP(N) std::cout << TYPE << N << " has no energy" << std::endl

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

ClapTrap::ClapTrap(void) : _name("generic"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	PRINT("ClapTrap: Default Constructor called");
	return;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	PRINT("ClapTrap: String Constructor called");
	return;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	PRINT("ClapTrap: Copy Constructor called");
	*this = src;

	return;
}

ClapTrap::~ClapTrap(void)
{
	PRINT("ClapTrap: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

#ifndef __GNUC__
#pragma region Function members
#endif

void ClapTrap::attack(const std::string &target)
{
	DEBUG_LOG("ClapTrap: attack function member called");

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

void ClapTrap::takeDamage(unsigned int amount)
{
	DEBUG_LOG("ClapTrap: takedamage function member called");

	if (this->_hitPoints == 0)
		PRINT(TYPE << this->_name << " is already broken! You Monster!");
	else
	{
		if (amount > this->_hitPoints)
			this->_hitPoints = 0;
		else
			this->_hitPoints -= amount;
		HIT(this->_name, amount);
	}
	return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	DEBUG_LOG("ClapTrap: beRepaired function member called");
	if (this->_energyPoints == 0)
		NO_EP(this->_name);
	else
	{
		this->_energyPoints--;
		this->_hitPoints += amount;
		REPAIR(this->_name, amount);
	}
	return;
}

#ifndef __GNUC__
#pragma endregion Function members
#endif

#ifndef __GNUC__
#pragma region Accessors
#endif

std::string ClapTrap::getName(void) const
{
	DEBUG_LOG("ClapTrap: getName function member called");
	return this->_name;
}

unsigned int ClapTrap::getHitPoints(void) const
{
	DEBUG_LOG("ClapTrap: getHitPoints function member called");
	return this->_hitPoints;
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
	DEBUG_LOG("ClapTrap: getenergyPoints function member called");
	return this->_energyPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const
{
	DEBUG_LOG("ClapTrap: getAttackDamage function member called");
	return this->_attackDamage;
}

void ClapTrap::setAttackDamage(unsigned int ad)
{
	DEBUG_LOG("ClapTrap: setAttackDamage function member called");

	this->_attackDamage = ad;
	return;
}

#ifndef __GNUC__
#pragma endregion Accessors
#endif

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	DEBUG_LOG("ClapTrap: Assignement operator called");

	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return *this;
}
