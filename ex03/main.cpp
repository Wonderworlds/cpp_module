/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:52:50 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/03 15:53:58 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>
#include <iomanip>

#define TITLE(A) PRINT(std::endl                         \
					   << std::setw(30)                  \
					   << "\033[0;33m" << A << "\033[0m" \
					   << std::endl)

int main()
{
	{
		TITLE("CONSTRUCTOR");
		{
		}
	}
	return 0;
}