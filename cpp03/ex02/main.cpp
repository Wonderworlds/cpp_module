/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:37:55 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/02 09:58:19 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <iomanip>

#define PRINT(A) std::cout << A << std::endl

#define TITLE(A) PRINT(std::endl                         \
					   << std::setw(30)                  \
					   << "\033[0;33m" << A << "\033[0m" \
					   << std::endl)

#define PRINT_STATE(A) PRINT(A.getName() << "\t| life: "                       \
										 << A.getHitPoints() << "\t| energy: " \
										 << A.getEnergyPoints()                \
										 << "\t| attackDamage: "               \
										 << A.getAttackDamage())

int main(void)
{
	{
		TITLE("CONSTRUCTOR");
		ClapTrap a;
		ClapTrap b("Joseph");
		FragTrap c("Albert");
		FragTrap d(c);
		FragTrap e = d;
		FragTrap f;

		TITLE("EASY");
		PRINT_STATE(a);
		PRINT_STATE(b);
		PRINT_STATE(c);
		PRINT_STATE(d);
		PRINT_STATE(e);
		PRINT_STATE(f);
		TITLE("DESTRUCTOR");
	}
	{
		TITLE("CHECK REPAIR");
		ClapTrap a("Joseph");
		FragTrap b("Albert");
		a.beRepaired(2);
		b.beRepaired(4294967295);
		PRINT("");
		PRINT_STATE(a);
		PRINT_STATE(b);
		PRINT("");
	}
	{
		TITLE("CHECK HGH5");
		FragTrap b("Albert");
		b.highFivesGuys();
	}
	{
		TITLE("CHECK ATTACK");
		FragTrap a("Albert");
		FragTrap b("Gasper");
		a.attack(b.getName());
		b.takeDamage(a.getAttackDamage());
		PRINT("");
		PRINT_STATE(a);
		PRINT_STATE(b);
		PRINT("");
		b.attack(a.getName());
		a.takeDamage(b.getAttackDamage());
		PRINT("");
		PRINT_STATE(a);
		PRINT_STATE(b);
		PRINT("");
		b.attack(a.getName());
		a.takeDamage(b.getAttackDamage());
		b.attack(a.getName());
		a.takeDamage(b.getAttackDamage());
		b.attack(a.getName());
		a.takeDamage(b.getAttackDamage());
		b.attack(a.getName());
		a.takeDamage(b.getAttackDamage());
		PRINT("");
		PRINT_STATE(a);
		PRINT("");
		TITLE("CHECK ATTACK DEATH");
		a.attack(b.getName());
		TITLE("CHECK High DEATH");
		a.highFivesGuys();
		TITLE("CHECK REPAIR DEATH");
		a.beRepaired(10);
		a.highFivesGuys();
	}
	{
		TITLE("CHECK ENERGY");
		int i = 0;
		FragTrap b("joseph");
		while (i < 100)
		{
			b.highFivesGuys();
			i++;
		}
		PRINT("");
		PRINT_STATE(b);
		PRINT("");
		TITLE("CHECK ENERGY High");
		b.highFivesGuys();
		TITLE("CHECK ENERGY attack");
		b.attack("nothing");
		TITLE("CHECK ENERGY repair");
		b.beRepaired(10);
	}
	return (0);
}
