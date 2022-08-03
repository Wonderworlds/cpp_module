/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:32:23 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/03 17:03:24 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

Character::Character(void) : ICharacter(), _name("default")
{
	DEBUG_LOG("Character: Default Constructor called");
	unsigned int idx = 0;
	while (idx < 4)
		this->_inventory[idx++] = NULL;
	return;
}

Character::Character(std::string const &name) : ICharacter(), _name(name)
{
	DEBUG_LOG("Character: String Constructor called");
	unsigned int idx = 0;
	while (idx < 4)
		this->_inventory[idx++] = NULL;
	return;
}

Character::Character(Character const &src) : ICharacter()
{
	DEBUG_LOG("Character: Copy Constructor called");
	*this = src;

	return;
}

Character::~Character(void)
{
	DEBUG_LOG("Character: Destructor called");
	unsigned int idx = 0;

	while (idx < 4)
		delete this->_inventory[idx];
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

std::string const &Character::getName() const
{
	return this->_name;
}

AMateria const *Character::getIndexInventory(int idx) const
{
	if (idx < 0 || idx >= 4)
		return NULL;
	return this->_inventory[idx];
}

void Character::equip(AMateria *m)
{
	DEBUG_LOG("Character: equip function member called");
	unsigned int idx = 0;

	if (!m)
		return;
	while (idx < 4 && this->_inventory[idx])
		idx++;
	if (idx < 4)
		this->_inventory[idx] = m->clone();
	return;
}

void Character::unequip(int idx)
{
	DEBUG_LOG("Character: unequip function member called");

	if (idx < 0 || idx >= 4)
		return;
	this->_inventory[idx] = NULL;
	return;
}

void Character::use(int idx, ICharacter &target)
{
	DEBUG_LOG("Character: use function member called");

	if (idx < 0 || idx >= 4)
		return;
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
	return;
}

Character &Character::operator=(Character const &rhs)
{
	DEBUG_LOG("Character: Assignement operator called");
	unsigned int idx = 0;
	AMateria const *tmp;
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		while (idx < 4)
		{
			if (this->_inventory[idx])
				delete this->_inventory[idx];
			if ((tmp = rhs.getIndexInventory(idx)))
				this->_inventory[idx] = tmp->clone();
			else
				this->_inventory[idx] = NULL;
			idx++;
		}
	}
	return *this;
}
