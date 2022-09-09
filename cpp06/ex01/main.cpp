/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:48:48 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/05 15:18:07 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <stdint.h>
#include "Data.hpp"


uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main(void)
{
	Data	*ptr = new Data(42);
	uintptr_t raw;

	PRINT(std::setw(16) <<  "adress ptr: " << ptr << " | value: " << ptr->getValue());
	raw = serialize(ptr);
	Data *new_ptr = deserialize(raw);
	// PRINT("raw: " << raw);
	PRINT(std::setw(16) << "adress new_ptr: " << new_ptr << " | value: " << new_ptr->getValue());
	return (0);
}