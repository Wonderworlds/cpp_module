/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:52:50 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/03 19:23:59 by fmauguin         ###   ########.fr       */
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
	{
		TITLE("ClASS CHECK");
		{
			TITLE("AMATERIA ICE");
			AMateria *a = new Ice();
			Ice *b = new Ice();
			AMateria *c = new Ice(*b);
			AMateria *d = new Ice();
			AMateria *e;
			Character bob("bob");
			e = a->clone();
			*d = *a;
			a->use(bob);
			delete a;
			b->use(bob);
			c->use(bob);
			d->use(bob);
			e->use(bob);
			delete b;
			delete c;
			delete d;
			delete e;
		}
		{
			TITLE("AMATERIA CURE");
			AMateria *a = new Cure();
			Cure *b = new Cure();
			AMateria *c = new Cure(*b);
			AMateria *d = new Cure();
			AMateria *e;
			Character bob("bob");
			e = a->clone();
			*d = *a;
			a->use(bob);
			delete a;
			b->use(bob);
			c->use(bob);
			d->use(bob);
			e->use(bob);
			delete b;
			delete c;
			delete d;
			delete e;
		}
		{
			TITLE("CHARACTER");
			ICharacter *a = new Character();
			Character *b = new Character("john");
			ICharacter *c = new Character(*b);
			Character *d = new Character("Evelynn");
			Character *e = new Character();
			Character bob("bob");
			*e = *d;
			PRINT("Character: a: " << a->getName());
			delete a;
			PRINT("Character: b: " << b->getName());
			delete b;
			PRINT("Character: c: " << c->getName());
			delete c;
			PRINT("Character: d: " << d->getName());
			delete d;
			PRINT("Character: e: " << e->getName());
			delete e;
		}
		{
			TITLE("MATERIASOURCE");
			IMateriaSource *a = new MateriaSource();
			MateriaSource *b = new MateriaSource();
			b->learnMateria(new Ice());
			IMateriaSource *c = new MateriaSource(*b);
			MateriaSource *d = new MateriaSource();
			d->learnMateria(new Cure());
			AMateria *tmp;

			PRINT("has Ice: a: " << ((tmp = a->createMateria("ice")) ? "true" : "false"));
			delete tmp;
			PRINT("has Cure: a: " << ((tmp = a->createMateria("cure")) ? "true" : "false"));
			delete tmp;
			delete a;
			PRINT("\nhas Ice: b: " << ((tmp = b->createMateria("ice")) ? "true" : "false"));
			delete tmp;
			PRINT("has Cure: b: " << ((tmp = b->createMateria("cure")) ? "true" : "false"));
			delete tmp;
			PRINT("\nhas Ice: c: " << ((tmp = c->createMateria("ice")) ? "true" : "false"));
			delete tmp;
			PRINT("has Cure: c: " << ((tmp = c->createMateria("cure")) ? "true" : "false"));
			delete tmp;
			delete c;
			PRINT("\nbefore assignment");
			PRINT("has Ice: d: " << ((tmp = d->createMateria("ice")) ? "true" : "false"));
			delete tmp;
			PRINT("has Cure: d: " << ((tmp = d->createMateria("cure")) ? "true" : "false"));
			delete tmp;
			*d = *b;
			delete b;
			PRINT("\nd = b\nafter assignment");
			PRINT("has Ice: d: " << ((tmp = d->createMateria("ice")) ? "true" : "false"));
			delete tmp;
			PRINT("has Cure: d: " << ((tmp = d->createMateria("cure")) ? "true" : "false"));
			delete tmp;
			delete d;
		}
	}
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
	{
		TITLE("TESTS CHARACTER");
		MateriaSource *src = new MateriaSource();
		Character me;
		Character bob("bob");
		AMateria *leftover = NULL;
		const AMateria *todel[4];

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		TITLE("TESTS equip ice");
		me.equip(src->createMateria("ice"));
		me.use(0, bob);
		TITLE("TESTS createMateria false");
		if (!src->createMateria("false"))
			PRINT("CREATE FAIL");
		if (!src->createMateria(""))
			PRINT("CREATE FAIL");
		TITLE("TESTS equip cure");
		me.equip(src->createMateria("cure"));
		me.use(1, bob);
		TITLE("TESTS equip ice overload");
		me.equip(src->createMateria("ice"));
		me.equip(src->createMateria("ice"));
		leftover = src->createMateria("ice");
		me.equip(leftover);
		me.equip(leftover);
		me.equip(leftover);
		delete leftover;
		me.use(0, bob);
		me.use(1, bob);
		me.use(2, bob);
		me.use(3, bob);
		me.use(4, bob);
		me.use(-1, bob);
		TITLE("TESTS unequip");
		todel[0] = me.getIndexInventory(0);
		todel[1] = me.getIndexInventory(1);
		todel[2] = me.getIndexInventory(2);
		todel[3] = me.getIndexInventory(3);
		me.unequip(0);
		me.unequip(1);
		me.unequip(2);
		me.unequip(3);
		me.unequip(4);
		me.unequip(-1);
		me.use(0, bob);
		me.use(1, bob);
		me.use(2, bob);
		me.use(3, bob);
		me.use(4, bob);
		delete todel[0];
		delete todel[1];
		delete todel[2];
		delete todel[3];
		PRINT("if empty == ok");
		TITLE("TESTS Equip unequip and equip again");
		me.equip(src->createMateria("ice"));
		me.equip(src->createMateria("ice"));
		me.use(0, bob);
		me.use(1, bob);
		PRINT("");
		todel[0] = me.getIndexInventory(0);
		me.unequip(0);
		me.use(0, bob);
		delete todel[0];
		PRINT("");
		me.equip(src->createMateria("cure"));
		me.equip(src->createMateria("cure"));
		me.use(0, bob);
		me.use(1, bob);
		me.use(2, bob);
		delete src;
	}
	return 0;
}