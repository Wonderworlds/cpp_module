/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:16:45 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/02 19:39:35 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const &src);
	virtual ~WrongAnimal(void);

	WrongAnimal &operator=(WrongAnimal const &rhs);
	const std::string &getType(void) const;
	void makeSound() const;
};

class WrongCat : public WrongAnimal
{
public:
	WrongCat(void);
	WrongCat(WrongCat const &src);
	~WrongCat(void);

	WrongCat &operator=(WrongCat const &rhs);
	void makeSound(void) const;
};

#endif