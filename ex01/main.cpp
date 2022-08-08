/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:03:44 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/08 16:04:38 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <iomanip>

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define STOPC "\033[0m"

#define TITLE(A) PRINT(std::endl               \
					   << std::setw(30)        \
					   << YELLOW << A << STOPC \
					   << std::endl)

void mult(int &line)
{
	line *= 2;
	return;
}

void strToUpper(std::string &line)
{
	std::size_t index = 0;

	while (line[index])
	{
		if (line[index] >= 'a' && line[index] <= 'z')
			line[index] -= 32;
		index++;
	}
}

int main(void)
{
	TITLE("TAB INT ==> *2");
	int tab[6] = {0, 1, 2, 3, 4, 5};

	PRINT("Start");
	iter(tab, 6, print);
	iter(tab, 6, mult);
	PRINT("\nafter");
	iter(tab, 6, print);
	PRINT("");
	TITLE("TAB strs ==> toUpper");

	std::string strs[4] = {"Hello", " 42 ", "world", "!"};
	PRINT("Start");
	iter(strs, 4, print);
	iter(strs, 4, strToUpper);
	PRINT("\nafter");
	iter(strs, 4, print);
	PRINT("");

	return (0);
}