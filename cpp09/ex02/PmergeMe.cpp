/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:26:11 by fmauguin          #+#    #+#             */
/*   Updated: 2023/09/07 18:02:11 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
	#define DEBUG_LOG(A) PRINT(A)
#else
	#define DEBUG_LOG(A)
#endif

#ifndef __GNUC__
#pragma region Constructor && Destructor
#endif

PmergeMe::PmergeMe(void) {
	DEBUG_LOG("PmergeMe: Default Constructor called");
	return ;
}

PmergeMe::PmergeMe(PmergeMe const & src) {
	DEBUG_LOG("PmergeMe: Copy Constructor called");
	*this = src;

	return ;
}

PmergeMe::~PmergeMe(void) {
	DEBUG_LOG("PmergeMe: Destructor called");
	return ;
}

#ifndef __GNUC__
#pragma endregion Constructor && Destructor
#endif


PmergeMe &	PmergeMe::operator=(PmergeMe const & rhs) {
	DEBUG_LOG("PmergeMe: Assignement operator called");
	(void)rhs;
	return *this;
}

bool PmergeMe::_isNumber(std::string const &str) const {
    return str.find_first_not_of("0123456789") == std::string::npos;
}

bool	PmergeMe::fillContainer(char **tab, size_t size) {
	
	for (size_t i = 0; i < size ; i++)
	{
		if (!_isNumber(tab[i]))
		{
			PRINT("Error: Invalid argument => " << tab[i]);
			return 1;
		}
		_vec.push_back(std::atoi(tab[i]));
		_lst.push_back(std::atoi(tab[i]));
		_deq.push_back(std::atoi(tab[i]));
	}
	return (0);
}

void PmergeMe::printOutput(void) const {
	std::vector<unsigned int>::const_iterator it;
	std::cout << "Before: ";
	it = _vec.begin();
	for (std::vector<unsigned int>::const_iterator i = _vec.begin(); i != _vec.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}