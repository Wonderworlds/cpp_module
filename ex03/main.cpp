/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:52:50 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/03 18:06:24 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include <iostream>
#include <iomanip>

#define TITLE(A) PRINT(std::endl                         \
					   << std::setw(30)                  \
					   << "\033[0;33m" << A << "\033[0m" \
					   << std::endl)

int main()
{
	// {
	// 	TITLE("CONSTRUCTOR");
	// 	{
	// 		ICharacter *c = new Character();
	// 		Character t("jose");

	// 		c->use(0, t);
	// 		c->unequip(0);
	// 		PRINT("");
	// 		delete c;
	// 	}
	// }
	{
		TITLE("MANDATORY");
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter *me = new Character("me");
		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter *bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	{
		TITLE("TESTS COPY PROFONDE");
		MateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		Character *me = new Character("me");
		AMateria *tmp;
		MateriaSource cp(*src);
		delete src;
		tmp = cp.createMateria("ice");
		me->equip(tmp);
		tmp = cp.createMateria("cure");
		me->equip(tmp);
		ICharacter *bob = new Character("bob");
		Character cp1(*me);
		delete me;
		cp1.use(0, *bob);
		cp1.use(1, *bob);
		delete bob;
	}
	return 0;
}