/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:34:56 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/02 19:39:51 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

class Animal
{
protected:
	std::string type;

public:
	Animal(void);
	Animal(Animal const &src);
	virtual ~Animal(void);

	Animal &operator=(Animal const &rhs);

	const std::string &getType(void) const;
	virtual void makeSound() const;
};

class Cat : public Animal
{
public:
	Cat(void);
	Cat(Cat const &src);
	~Cat(void);

	Cat &operator=(Cat const &rhs);
	virtual void makeSound(void) const;
};

class Dog : public Animal
{
public:
	Dog(void);
	Dog(Dog const &src);
	~Dog(void);

	Dog &operator=(Dog const &rhs);
	virtual void makeSound(void) const;
};

#endif