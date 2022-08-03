/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:34:56 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/03 15:45:20 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

class AAnimal
{
protected:
	std::string type;

public:
	AAnimal(void);
	AAnimal(AAnimal const &src);
	virtual ~AAnimal(void);

	AAnimal &operator=(AAnimal const &rhs);

	std::string const &getType(void) const;
	virtual void makeSound() const = 0;
};

class Cat : public AAnimal
{
private:
	Brain *_brain;

public:
	Cat(void);
	Cat(Cat const &src);
	~Cat(void);

	Cat &operator=(Cat const &rhs);
	Brain const *getBrain(void) const;
	virtual void makeSound(void) const;
};

class Dog : public AAnimal
{
private:
	Brain *_brain;

public:
	Dog(void);
	Dog(Dog const &src);
	~Dog(void);

	Dog &operator=(Dog const &rhs);
	Brain const *getBrain(void) const;
	virtual void makeSound(void) const;
};

#endif