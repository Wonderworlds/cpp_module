/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:33:37 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/02 19:40:42 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include <iostream>
#include <iomanip>

#define TITLE(A) PRINT(std::endl                         \
					   << std::setw(30)                  \
					   << "\033[0;33m" << A << "\033[0m" \
					   << std::endl)

int main()
{
	{
		TITLE("MANDATORY");
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); // will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}
	{
		TITLE("WRONG");
		const WrongAnimal *meta = new WrongAnimal();
		const WrongAnimal *i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); // will output the cat sound!
		meta->makeSound();
		delete meta;
		delete i;
	}
#ifdef DEBUG
	{
		TITLE("CONSTRUCTOR");
		{
			TITLE("Animal");
			Animal a;
			Animal b(a);
			Animal c;
			c = b;
		}
		{
			TITLE("Cat");
			Cat a;
			Cat b(a);
			Cat c;
			c = b;
		}
		{
			TITLE("Dog");
			Dog a;
			Dog b(a);
			Dog c;
			c = b;
		}
	}
#endif
	return 0;
}