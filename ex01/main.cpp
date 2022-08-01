/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:37:55 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/01 19:04:44 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
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
		ScavTrap c("Albert");
		ScavTrap d(c);
		ScavTrap e;

		TITLE("EASY");
		PRINT_STATE(a);
		PRINT_STATE(b);
		PRINT_STATE(c);
		PRINT_STATE(d);
		PRINT_STATE(e);
		TITLE("DESTRUCTOR");
	}
	{
		TITLE("CHECK REPAIR");
		ClapTrap a("Joseph");
		ScavTrap b("Albert");
		a.beRepaired(2);
		b.beRepaired(2);
	}
	{
		TITLE("CHECK GUARD");
		ScavTrap b("Albert");
		b.guardGate();
	}
	{
		TITLE("CHECK ATTACK");
		ScavTrap a("Albert");
		ScavTrap b("Gasper");
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
		TITLE("CHECK GUARD DEATH");
		a.guardGate();
		TITLE("CHECK REPAIR DEATH");
		a.beRepaired(10);
		a.guardGate();
	}
	{
		TITLE("CHECK ENERGY");
		int i = 0;
		ScavTrap b("joseph");
		while (i < 50)
		{
			b.guardGate();
			i++;
		}
		PRINT("");
		PRINT_STATE(b);
		PRINT("");
		TITLE("CHECK ENERGY guard");
		b.guardGate();
		TITLE("CHECK ENERGY attack");
		b.attack("nothing");
		TITLE("CHECK ENERGY repair");
		b.beRepaired(10);
	}
	return (0);
}
