/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:37:55 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/02 10:00:09 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
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
		DiamondTrap a;
		DiamondTrap b("jose");
		DiamondTrap c = b;
		DiamondTrap d(a);

		TITLE("EASY");
		PRINT_STATE(a);
		PRINT_STATE(b);
		PRINT_STATE(c);
		PRINT_STATE(d);
		PRINT("");
		a.whoAmI();
		b.whoAmI();
		c.whoAmI();
		d.whoAmI();
		TITLE("DESTRUCTOR");
	}
	{
		TITLE("FUNCTION");
		DiamondTrap a("jose");
		PRINT("");
		PRINT_STATE(a);
		PRINT("");
		a.attack("nothing");
		a.guardGate();
		a.highFivesGuys();
		a.whoAmI();
		a.beRepaired(4294967295);
		a.takeDamage(5);
		PRINT("");
		PRINT_STATE(a);
		PRINT("");
		TITLE("DEATH");
		a.takeDamage(4294967295);
		PRINT("");
		PRINT_STATE(a);
		PRINT("");
		TITLE("DEATH attack");
		a.attack("nothing");
		TITLE("DEATH guard");
		a.guardGate();
		TITLE("DEATH high");
		a.highFivesGuys();
		TITLE("DEATH who");
		a.whoAmI();
		TITLE("DEATH ==> REPAIR");
		PRINT("");
		PRINT_STATE(a);
		PRINT("");
		a.beRepaired(10);
		PRINT("");
		PRINT_STATE(a);
		PRINT("");
		TITLE("DEATH ==> repair attack");
		a.attack("nothing");
		TITLE("DEATH ==> repair guard");
		a.guardGate();
		TITLE("DEATH ==> repair high");
		a.highFivesGuys();
		TITLE("DEATH ==> repair who");
		a.whoAmI();
		TITLE("ENERGY");
		PRINT("");
		PRINT_STATE(a);
		PRINT("");
		int i = 40;
		while (i--)
			a.whoAmI();
		PRINT("");
		PRINT_STATE(a);
		PRINT("");
		TITLE("ENERGY attack");
		a.attack("nothing");
		TITLE("ENERGY guard");
		a.guardGate();
		TITLE("ENERGY high");
		a.highFivesGuys();
		TITLE("ENERGY who");
		a.whoAmI();
		TITLE("DESTRUCTOR");
	}
	return (0);
}
