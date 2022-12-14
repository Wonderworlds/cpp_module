/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:21:26 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/09 14:46:06 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
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

bool strIsDigit(const char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (false);
		str++;
	}
	return (true);
}

int _strType(const char *str, int *precision)
{
	std::size_t index = 0, before = 0;
	bool hasDecimal = false;

	while (*str && ((*str >= 9 && *str <= 13) || *str == ' '))
	{
		str++;
		before++;
	}
	if (*str == '-' || *str == '+')
	{
		before++;
		str++;
	}
	while (str[index])
	{
		if (str[index] == '.')
			hasDecimal = true;
		if (hasDecimal && str[index] >= '0' && str[index] <= '9')
			*precision += 1;
		index++;
	}
	if (*precision == 0)
		*precision = 1;
	if ((index <= 1 && before == 0) || (index == 0 && before == 1))
		return (0);
	else if (strIsDigit(str))
		return (1);
	else if (str[index - 1] == 'f' || str[index - 1] == 'F')
		return (2);
	else
		return (3);
}

int __convert(char *arg)
{
	char *endstr = NULL;
	double d;
	int precision = 0;
	int choice;
	ScalaireClass *ptr = NULL;

	choice = _strType(arg, &precision);
	switch (choice)
	{
	case 0:
		ptr = new (std::nothrow) ScalaireClass(arg[0], precision);
		break;
	case 1:
		d = std::strtod(arg, &endstr);
		if (endstr == arg && d == 0)
			return (__err_arg("arg invalid: no conversion can be performed"), 1);
		if (endstr && endstr[0])
			return (__err_arg("arg invalid: not entirely digit"), 1);
		else if (d > INT_MAX || d < INT_MIN)
			return (__err_arg("arg invalid: int overflow"), 1);
		ptr = new (std::nothrow) ScalaireClass(static_cast<int>(d), precision);
		break;
	case 2:
		d = std::strtod(arg, &endstr);
		if (endstr == arg && d == 0)
			return (__err_arg("arg invalid: no conversion can be performed"), 1);
		if ((d == INFINITY || d == -INFINITY) && endstr && !endstr[0])
		{
			ptr = new (std::nothrow) ScalaireClass(d, precision);
			break;
		}
		if (endstr && !((endstr[0] == 'f' || endstr[0] == 'F') && !endstr[1]))
			return (__err_arg("arg invalid: not entirely digit"), 1);
		else if (!(d == INFINITY || d == -INFINITY) && (d == HUGE_VAL || d > __FLT_MAX__ || d < -__FLT_MAX__))
			return (__err_arg("arg invalid: float overflow"), 1);
		ptr = new (std::nothrow) ScalaireClass(static_cast<float>(d), precision);
		break;
	case 3:
		d = std::strtod(arg, &endstr);
		if (endstr == arg && d == 0)
			return (__err_arg("arg invalid: no conversion can be performed"), 1);
		if (endstr && endstr[0])
			return (__err_arg("arg invalid: not entirely digit"), 1);
		if (d == HUGE_VAL)
			return (__err_arg("arg invalid: double overflow"), 1);
		ptr = new (std::nothrow) ScalaireClass(d, precision);
		break;
	default:
		return (__err_arg("arg invalid"), 1);
		break;
	}
	if (ptr)
	{
		ptr->print();
		delete ptr;
	}
	else
	{
		std::cerr << "Fail alloc" << std::endl;
	}
	return (0);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (__err_arg("error, need only 1 argument"), 1);
	__convert(av[1]);
	return (0);
}