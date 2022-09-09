/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:53:18 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/03 17:21:15 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "Character.hpp"

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

class ICharacter;

class AMateria
{
protected:
	std::string _type;

public:
	AMateria(void);
	AMateria(std::string const &type);
	AMateria(AMateria const &src);
	virtual ~AMateria(void);

	AMateria &operator=(AMateria const &rhs);
	std::string const &getType(void) const;

	virtual AMateria *clone(void) const = 0;
	virtual void use(ICharacter &target);
};

class Ice : public AMateria
{
public:
	Ice(void);
	Ice(Ice const &src);
	~Ice(void);
	Ice &operator=(Ice const &rhs);
	AMateria *clone(void) const;
	virtual void use(ICharacter &target);
};

class Cure : public AMateria
{
public:
	Cure(void);
	Cure(Cure const &src);
	~Cure(void);
	Cure &operator=(Cure const &rhs);
	AMateria *clone(void) const;
	virtual void use(ICharacter &target);
};

#endif