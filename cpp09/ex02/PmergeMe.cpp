/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:26:11 by fmauguin          #+#    #+#             */
/*   Updated: 2023/09/07 23:18:11 by fmauguin         ###   ########.fr       */
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

PmergeMe::PmergeMe(void) : _odd(false)
{
	DEBUG_LOG("PmergeMe: Default Constructor called");
	return;
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	DEBUG_LOG("PmergeMe: Copy Constructor called");
	*this = src;

	return;
}

PmergeMe::~PmergeMe(void)
{
	DEBUG_LOG("PmergeMe: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	DEBUG_LOG("PmergeMe: Assignement operator called");
	(void)rhs;
	return *this;
}

bool PmergeMe::_isNumber(std::string const &str) const
{
	return str.find_first_not_of("0123456789") == std::string::npos;
}

bool PmergeMe::init(char **tab, size_t size)
{

	if (size % 2 == 1)
		_odd = true;
	for (size_t i = 0; i < size - _odd; i += 2)
	{
		if (!_isNumber(tab[i]))
		{
			PRINT("Error: Invalid argument => " << tab[i]);
			return 1;
		}
		else if (!_isNumber(tab[i + 1]))
		{
			PRINT("Error: Invalid argument => " << tab[i + 1]);
			return 1;
		}
		_vec.push_back(std::make_pair(std::atoi(tab[i]), std::atoi(tab[i + 1])));
		_deq.push_back(std::make_pair(std::atoi(tab[i]), std::atoi(tab[i + 1])));
	}
	if (_odd)
	{
		if (!_isNumber(tab[size - 1]))
		{
			PRINT("Error: Invalid argument => " << tab[size - 1]);
			return 1;
		}
		_stow_away = std::atoi(tab[size - 1]);
	}
	std::cout << "Before: ";
	for (size_t i = 0; i < size; i++)
	{
		if (i == 4 && size > 5)
		{
			std::cout << " [...]";
			break;
		}
		std::cout << " " << tab[i];
	}
	std::cout << std::endl;
	return (0);
}

void PmergeMe::solve(void)
{
	std::vector<unsigned int> vec1, vec2;
	std::vector<unsigned int> deq1, deq2;
	double t_vec, t_deq;

	if (_odd)
	{
		t_vec = _FJ_Algo(_vec, vec2, vec1, _stow_away);
		t_deq = _FJ_Algo(_deq, deq2, deq1, _stow_away);
	}
	else
	{
		t_vec = _FJ_Algo(_vec, vec2, vec1, -1);
		t_deq = _FJ_Algo(_deq, deq2, deq1, -1);
	}
	std::cout << "After: ";
	for (size_t i = 0; i < deq1.size(); i++)
	{
		if (i == 4 && deq1.size() > 5)
		{
			std::cout << " [...]";
			break;
		}
		std::cout << " " << deq1[i];
	}
	std::cout << std::endl;
	PRINT("Time to process a range of " << vec1.size() << " elements with std::vector<> : " << t_vec << " us");
	PRINT("Time to process a range of " << deq1.size() << " elements with std::deque<>  : " << t_deq << " us");
}
