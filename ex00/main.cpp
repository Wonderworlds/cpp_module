/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:08:32 by adesgran          #+#    #+#             */
/*   Updated: 2022/08/07 21:43:40 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <easyfind.hpp>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <map>
#include <iterator>
#include <exception>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;36m"
#define PURPLE "\033[0;35m"
#define STOPC "\033[0m"

#define PRINT(A) std::cout << A << std::endl

#define TITLE(A) PRINT(std::endl               \
					   << std::setw(30)        \
					   << YELLOW << A << STOPC \
					   << std::endl)

#define PRINT_CONTAINER(A, B, T)                       \
	std::cout << PURPLE "Array: " YELLOW;              \
	for (T::iterator i = A.begin(); i != A.end(); i++) \
	{                                                  \
		std::cout << *i << " ";                        \
	}                                                  \
	std::cout << STOPC << std::endl;

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

#define TEST(C, T)                                                  \
	TITLE(C " | " << #T);                                           \
	{                                                               \
		T a;                                                        \
		{                                                           \
			PRINT(BLUE "easyfind(a, 0) in empty " C STOPC);         \
			try                                                     \
			{                                                       \
				ret = *easyfind(a, 0);                              \
				PRINT(GREEN "RET = " << ret << STOPC);              \
			}                                                       \
			catch (const std::exception &e)                         \
			{                                                       \
				PRINT(RED << e.what() << STOPC);                    \
			}                                                       \
		}                                                           \
		PRINT(BLUE "\nfill " C STOPC);                              \
		for (size_t i = 0; i < 10; i++)                             \
			a.push_back(i * 3);                                     \
		a.push_back(15);                                            \
		a.push_back(42);                                            \
		PRINT_CONTAINER(a, 12, T)                                   \
		try                                                         \
		{                                                           \
			PRINT(BLUE "easyfind(a, 18) basic" STOPC);              \
			ret = *easyfind(a, 18);                                 \
			PRINT(GREEN "RET = " << ret << STOPC);                  \
			PRINT(BLUE "easyfind(a, 15) multiple occurence" STOPC); \
			ret = *easyfind(a, 15);                                 \
			PRINT(GREEN "RET = " << ret << STOPC);                  \
			PRINT(BLUE "check iterator +1" STOPC);                  \
			ret = *(++easyfind(a, 15));                             \
			PRINT(GREEN "RET + 1 = " << ret << STOPC);              \
			PRINT(BLUE "easyfind(a, 1) fail" STOPC);                \
			ret = *easyfind(a, 1);                                  \
			PRINT(GREEN "RET = " << ret << STOPC);                  \
		}                                                           \
		catch (const std::exception &e)                             \
		{                                                           \
			PRINT(RED << e.what() << STOPC);                        \
		}                                                           \
	}

int main(void)
{
	int ret;

	TEST("vector", std::vector<int>)
	TEST("list", std::list<int>)
	TEST("deque", std::deque<int>)
	return (0);
}