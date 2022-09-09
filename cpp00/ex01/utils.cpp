/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:23:04 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/28 13:36:55 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static int	str_digit(std::string s)
{
	std::string::iterator it = s.begin();

	if (s.empty())
		return (1);
	while (it != s.end() && *it >= '0' && *it <= '9')
		it++;
	if (it != s.end())
		return (1);
	return (0);
}

std::string	get_field(const char *field) {
	std::string	ret;

	std::cout << field;
	std::getline (std::cin,ret);
	while (ret.empty())
	{
		std::cout << "\033[A\33[2K\r" << "Error input empty | " << field;
		std::getline (std::cin,ret);
	}
	return (ret);
}

std::string	get_field_number(const char *field) {
	std::string	ret;

	std::cout << field;
	std::getline (std::cin,ret);
	while (str_digit(ret))
	{
		std::cout << "\033[A\33[2K\r" << "Error input not digits: " << ret << " | " << field;
		std::getline (std::cin,ret);
	}
	return (ret);
}