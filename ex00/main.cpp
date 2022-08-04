/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:21:26 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/04 19:22:53 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include "ScalaireClass.hpp"

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

void __err_arg(void)
{
	PRINT("error invalid arg");
}

void __convert(std::string arg)
{
	ScalaireClass *ptr = NULL;
	double number;
	std::size_t size;
	size = arg.size();
	if (size == 1)
		ptr = new ScalaireClass(arg[0]);
	else
	{
		number = std::atof(arg.c_str());
		if (size != arg.size())
			return __err_arg();
		if (!arg.find('.', 0) && number <= std::numeric_limits<int>::max() && number >= std::numeric_limits<int>::min())
			ptr = new ScalaireClass(static_cast<int>(number));
		else if (number <= std::numeric_limits<float>::max() && number >= std::numeric_limits<float>::min())
			ptr = new ScalaireClass(static_cast<float>(number));
		else
			ptr = new ScalaireClass(number);
	}
	if (ptr)
	{
		ptr->print();
		delete ptr;
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (__err_arg(), 1);
	__convert(av[1]);
	return (0);
}