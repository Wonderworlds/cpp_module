/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:27:24 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/03 17:34:36 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria *) = 0;
	virtual AMateria *createMateria(std::string const &type) = 0;
};

class MateriaSource : public IMateriaSource
{
private:
	AMateria *_memory[4];

public:
	MateriaSource(void);
	MateriaSource(MateriaSource const &src);
	~MateriaSource(void);

	MateriaSource &operator=(MateriaSource const &rhs);
	AMateria const *getIndexMemory(int idx) const;

	void learnMateria(AMateria *);
	AMateria *createMateria(std::string const &type);
};

#endif