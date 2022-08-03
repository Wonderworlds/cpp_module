/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:30:56 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/03 17:59:44 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

MateriaSource::MateriaSource(void) : IMateriaSource()
{
	DEBUG_LOG("MateriaSource: Default Constructor called");
	unsigned int idx = 0;
	while (idx < 4)
		this->_memory[idx++] = NULL;
	return;
}

MateriaSource::MateriaSource(MateriaSource const &src) : IMateriaSource()
{
	DEBUG_LOG("MateriaSource: Copy Constructor called");
	unsigned int idx = 0;
	while (idx < 4)
		this->_memory[idx++] = NULL;
	*this = src;

	return;
}

MateriaSource::~MateriaSource(void)
{
	DEBUG_LOG("MateriaSource: Destructor called");
	unsigned int idx = 0;

	while (idx < 4)
		delete this->_memory[idx++];
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

AMateria const *MateriaSource::getIndexMemory(int idx) const
{
	if (idx < 0 || idx >= 4)
		return NULL;
	return this->_memory[idx];
}

void MateriaSource::learnMateria(AMateria *m)
{
	DEBUG_LOG("MateriaSource: learnMateria function member called");
	unsigned int idx = 0;

	if (!m)
		return;
	while (idx < 4 && this->_memory[idx])
		idx++;
	if (idx < 4)
		this->_memory[idx] = m;
	return;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	DEBUG_LOG("MateriaSource: createMateria function member called");
	unsigned int idx = 0;

	while (idx < 4)
	{
		if (this->_memory[idx] && !type.compare(this->_memory[idx]->getType()))
			return (this->_memory[idx]->clone());
		idx++;
	}
	return 0;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs)
{
	DEBUG_LOG("MateriaSource: Assignement operator called");
	unsigned int idx = 0;
	AMateria const *tmp;

	if (this != &rhs)
	{
		while (idx < 4)
		{
			if (this->_memory[idx])
				delete this->_memory[idx];
			if ((tmp = rhs.getIndexMemory(idx)))
				this->_memory[idx] = tmp->clone();
			else
				this->_memory[idx] = NULL;
			idx++;
		}
	}
	return *this;
}
