/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:37:55 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/01 18:12:07 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <iomanip>

#define TITLE(A) std::cout << std::endl                      \
						   << std::setw(30)                  \
						   << "\033[0;33m" << A << "\033[0m" \
						   << std::endl                      \
						   << std::endl

#define PRINT(A) std::cout << A << std::endl

int main(void)
{
	TITLE("CONSTRUCTOR");
	ClapTrap a;
	ClapTrap b("Joseph");

	TITLE("EASY");
	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(2);

	TITLE("CHECK ENERGY");
	int i = 0;
	while (i < 12)
	{
		b.beRepaired(2);
		i++;
	}
	b.attack(a.getName());
	return (0);
}
