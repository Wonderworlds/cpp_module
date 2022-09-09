/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:37:55 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/02 09:56:41 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
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
		ClapTrap c(b);
		ClapTrap d = b;

		TITLE("EASY");
		PRINT_STATE(a);
		PRINT_STATE(b);
		PRINT_STATE(c);
		PRINT_STATE(d);
		TITLE("DESTRUCTOR");
	}
	{
		TITLE("CHECK REPAIR");
		ClapTrap a("Joseph");
		a.beRepaired(2);
	}
	{
		TITLE("CHECK ATTACK");
		ClapTrap a("Albert");
		ClapTrap b("Gasper");
		a.attack(b.getName());
		b.takeDamage(a.getAttackDamage());
		PRINT("");
		PRINT_STATE(a);
		PRINT_STATE(b);
		PRINT("");
		TITLE("CHECK DEATH");
		b.setAttackDamage(10);
		PRINT("");
		PRINT_STATE(a);
		PRINT_STATE(b);
		PRINT("");
		b.attack(a.getName());
		a.takeDamage(b.getAttackDamage());
		PRINT("");
		PRINT_STATE(a);
		PRINT("");
		TITLE("CHECK DEATH takeDamage");
		a.takeDamage(b.getAttackDamage());
		TITLE("CHECK DEATH ATTACK");
		a.attack(b.getName());
		TITLE("CHECK DEATH REPAIR");
		a.beRepaired(2);
		PRINT("");
		PRINT_STATE(a);
		PRINT("");
		TITLE("CHECK ATTACK after repair");
		a.attack(b.getName());
	}
	{
		TITLE("CHECK ENERGY");
		int i = 0;
		ClapTrap b("joseph");
		while (i < 10)
		{
			b.beRepaired(4294967295);
			i++;
		}
		PRINT("");
		PRINT_STATE(b);
		PRINT("");
		TITLE("CHECK ENERGY attack");
		b.attack("nothing");
		TITLE("CHECK ENERGY repair");
		b.beRepaired(10);
	}
	return (0);
}
