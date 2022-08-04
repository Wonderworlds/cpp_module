/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:21:26 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/04 20:24:06 by fmauguin         ###   ########.fr       */
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

void __err_arg(const char *str)
{
	std::cerr << str << std::endl;
}

int __getNumber(double *number, const char *str)
{
	char *endstr;
	long double ld = std::strtold(str, &endstr);
	if (ld > std::numeric_limits<double>::max() || ld < -std::numeric_limits<double>::max() - 1)
		return (__err_arg("arg invalid: overflow"), 1);
	if (endstr && endstr[0])
		return (__err_arg("arg invalid: not entirely digit"), 1);
	*number = static_cast<double>(ld);
	return (0);
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
		if (__getNumber(&number, arg.c_str()))
			return;
		if (arg.find('.') == std::string::npos && number <= std::numeric_limits<int>::max() && number >= -std::numeric_limits<int>::max() - 1)
		{
			ptr = new ScalaireClass(static_cast<int>(number));
		}
		else if (number <= std::numeric_limits<float>::max() && number >= -std::numeric_limits<float>::max() - 1)
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
		return (__err_arg("error, need only 1 argument"), 1);
	__convert(av[1]);
	return (0);
}