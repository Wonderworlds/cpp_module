/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:33:37 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/03 15:28:18 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>
#include <iomanip>

#define TITLE(A) PRINT(std::endl                         \
					   << std::setw(30)                  \
					   << "\033[0;33m" << A << "\033[0m" \
					   << std::endl)

int main()
{
	{
		TITLE("CONSTRUCTOR");
		{
			TITLE("Cat");
			Cat *a = new (std::nothrow) Cat();
			Cat *b = new (std::nothrow) Cat(*a);
			Cat *c = new (std::nothrow) Cat();
			if (c && b)
				*c = *b;
			PRINT("");
			if (a)
				delete a;
			if (b)
				delete b;
			if (c)
				delete c;
		}
		{
			TITLE("Dog");
			Dog *a = new (std::nothrow) Dog();
			Dog *b = new (std::nothrow) Dog(*a);
			Dog *c = new (std::nothrow) Dog();
			if (c && b)
				*c = *b;
			PRINT("");
			if (a)
				delete a;
			if (b)
				delete b;
			if (c)
				delete c;
		}
	}
	{
		TITLE("MANDATORY");
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		delete j; // should not create a leak
		delete i;
	}
	{
		TITLE("CHECK COPY");
		const Cat c;
		const Cat *j = new Cat(c);

		PRINT("");
		PRINT("c brain adress " << c.getBrain());
		PRINT("j brain adress " << j->getBrain());
		PRINT("");
		delete j;
	}
	{
		TITLE("Loop");
		Animal *j[10];
		int i = 10;
		while (--i)
		{
			if (i % 2)
				j[i] = new Cat();
			else
				j[i] = new Dog();
			PRINT("");
		}
		i = 10;
		while (--i)
		{
			PRINT("");
			delete j[i];
		}
	}
	return 0;
}