/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:21:26 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/05 12:53:55 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>
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

void	_strToLower(std::string &str)
{
	std::string::iterator it = str.begin();
	char c;

	while (it != str.end())
	{
		c = static_cast<char>(std::tolower(*it));
		*it = c;
		it++;
	}
}

int __convert(std::string arg)
{
	std::size_t size;
	char *endstr = NULL;

	size = arg.size();

	if (size == 1)
	{
		ScalaireClass tmp(arg[0]);
		tmp.print();
	}
	else
	{
		_strToLower(arg);
		if (arg.find_first_not_of("0123456789") == std::string::npos)
		{
			long int li = std::strtol(arg.c_str(), &endstr, 10);
			if (li > std::numeric_limits<int>::max() || li < std::numeric_limits<int>::min())
				return (__err_arg("arg invalid: int overflow"), 1);
			if (endstr == arg.c_str() && li == 0)
				return (__err_arg("arg invalid: no conversion can be performed"), 1);
			if (endstr && endstr[0])
				return (__err_arg("arg invalid: not entirely digit"), 1);
			ScalaireClass tmp(static_cast<int>(li));
			tmp.print();
		}
		else if (arg.find('f') == std::string::npos)
		{
			double d = std::strtod(arg.c_str(), &endstr);
			if (d == HUGE_VAL)
				return (__err_arg("arg invalid: double overflow"), 1);
			if (endstr == arg.c_str() && d == 0)
				return (__err_arg("1arg invalid: no conversion can be performed"), 1);
			if (endstr && endstr[0])
				return (__err_arg("arg invalid: not entirely digit"), 1);
			ScalaireClass tmp(d);
			tmp.print();
		}
		else
		{
			float f;
			double d = std::strtod(arg.c_str(), &endstr);
			if (arg.find("inff", 0) == std::string::npos
				&& (d == std::numeric_limits<double>::infinity()
					|| d == -std::numeric_limits<double>::infinity()))
			{
				ScalaireClass tmp(d);
				tmp.print();
				return (0);
			}
			if (d == std::numeric_limits<float>::infinity())
				f = std::numeric_limits<float>::infinity();
			else if (d == -std::numeric_limits<float>::infinity())
				f = -std::numeric_limits<float>::infinity();
			else
			{
				if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
					return (__err_arg("arg invalid: float overflow"), 1);
				if (endstr == arg.c_str() && d == 0)
					return (__err_arg("arg invalid: no conversion can be performed"), 1);
				if (endstr && endstr[0] && !(endstr[0] == 'f' && !endstr[1]))
					return (__err_arg("arg invalid: not entirely digit"), 1);
				f = static_cast<float>(d);
			}
			ScalaireClass tmp(f);
			tmp.print();
		}
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