/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:06:08 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/01 16:49:02 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

#define ATTACK(N, T, D) std::cout << "ClapTrap " << N << " attacks " << T << ", causing " << D << " points of damage!" << std::endl;
#define HIT(N, D) std::cout << "ClapTrap " << N << " takes " << D << " points of damage!" << std::endl;
#define REPAIR(N, D) std::cout << "ClapTrap " << N << " is repaired for " << D << " hit points!" << std::endl;
#define USELESS(N) std::cout << "ClapTrap " << N << " can't move" << std::endl;

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

ClapTrap::ClapTrap(void) : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default Constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "String Constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = src;

	return;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
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
#ifdef DEBUG
	std::cout << "attack function member called" << std::endl;
#endif
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		USELESS(this->_name);
		return;
	}
	this->_energyPoints--;
	ATTACK(this->_name, target, this->_attackDamage)
	return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
#ifdef DEBUG
	std::cout << "takeDamage function member called" << std::endl;
#endif
	if (amount > this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	HIT(this->_name, amount)
	return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
#ifdef DEBUG
	std::cout << "beRepaired function member called" << std::endl;
#endif
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		USELESS(this->_name);
		return;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	REPAIR(this->_name, amount)
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
#ifdef DEBUG
	std::cout << "getName function member called" << std::endl;
#endif
	return this->_name;
}

unsigned int ClapTrap::getHitPoints(void) const
{
#ifdef DEBUG
	std::cout << "getHitPoints function member called" << std::endl;
#endif
	return this->_hitPoints;
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
#ifdef DEBUG
	std::cout << "getenergyPoints function member called" << std::endl;
#endif
	return this->_energyPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const
{
#ifdef DEBUG
	std::cout << "getAttackDamage function member called" << std::endl;
#endif
	return this->_attackDamage;
}

#ifndef __GNUC__
#pragma endregion Accessors
#endif

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
#ifdef DEBUG
	std::cout << "Assignement operator called" << std::endl;
#endif

	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return *this;
}
