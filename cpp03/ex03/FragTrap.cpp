/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:58:08 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/01 19:30:46 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

#define TYPE "FragTrap: "
#define ATTACK(N, T, D) std::cout << TYPE << N << " attacks " << T << ", causing " << D << " points of damage!" << std::endl
#define HIGHFIVES(N) std::cout << TYPE << N << " Everyone, I need a High Five!" << std::endl
#define NO_HP(N) std::cout << TYPE << N << " is broken! Need repair" << std::endl
#define NO_EP(N) std::cout << TYPE << N << " has no energy" << std::endl

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

FragTrap::FragTrap(void) : ClapTrap()
{
	PRINT("FragTrap: Default Constructor called");
	this->_attackDamage = 30;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	return;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	PRINT("FragTrap: String Constructor called");
	this->_attackDamage = 30;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	return;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	PRINT("FragTrap: Copy Constructor called");
	*this = src;

	return;
}

FragTrap::~FragTrap(void)
{
	PRINT("FragTrap: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

#ifndef __GNUC__
#pragma region function members
#endif

void FragTrap::attack(const std::string &target)
{
	DEBUG_LOG("FragTrap: attack function member called");

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

void FragTrap::highFivesGuys(void)
{
	DEBUG_LOG("FragTrap: highFivesGuys function member called");

	if (this->_hitPoints == 0)
		NO_HP(this->_name);
	else if (this->_energyPoints == 0)
		NO_EP(this->_name);
	else
	{
		this->_energyPoints--;
		HIGHFIVES(this->_name);
	}
	return;
}

#ifndef __GNUC__
#pragma endregion function members
#endif

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	DEBUG_LOG("FragTrap: Assignement operator called");
	if (this != &rhs)
	{
		this->_attackDamage = rhs.getAttackDamage();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
	}
	return *this;
}
