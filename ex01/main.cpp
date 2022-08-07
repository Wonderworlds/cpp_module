/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 21:47:29 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/08 00:15:06 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <Span.hpp>

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

#define PRINT_CONTAINER(A, T)                                \
	std::cout << PURPLE "List: " YELLOW;                     \
	for (T::const_iterator i = A.begin(); i != A.end(); i++) \
	{                                                        \
		std::cout << *i << " ";                              \
	}                                                        \
	std::cout << STOPC << std::endl;

#define TRY(A, B)                        \
	PRINT(BLUE #A B STOPC);              \
	try                                  \
	{                                    \
		std::cout << A << std::endl;     \
	}                                    \
	catch (const std::exception &e)      \
	{                                    \
		PRINT(RED << e.what() << STOPC); \
	}

#define TRY_F(A, B)                      \
	PRINT(BLUE #A B STOPC);              \
	try                                  \
	{                                    \
		A;                               \
	}                                    \
	catch (const std::exception &e)      \
	{                                    \
		PRINT(RED << e.what() << STOPC); \
	}
#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

int main()
{
	{
		TITLE("Mandatory");
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		PRINT_CONTAINER(sp.getList(), std::list<int>)
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		{
			TITLE("Test perso");

			Span sp = Span(10);

			PRINT_CONTAINER(sp.getList(), std::list<int>)
			TRY(sp.shortestSpan(), " empty list")
			TRY(sp.longestSpan(), " empty list")

			sp.addNumber(42);
			PRINT_CONTAINER(sp.getList(), std::list<int>)
			TRY(sp.shortestSpan(), " size == 1")
			TRY(sp.longestSpan(), " size == 1")
		}
		Span sp = Span(10);
		std::list<int> a;

		a.push_back(6);
		a.push_back(3);
		a.push_back(17);
		a.push_back(9);
		a.push_back(11);

		TITLE("Test fillList and overflow list");

		PRINT(BLUE "fill" STOPC);
		sp.fillList(a.begin(), a.end());
		PRINT_CONTAINER(sp.getList(), std::list<int>)

		PRINT(BLUE "fill" STOPC);
		sp.fillList(a.begin(), a.end());
		PRINT_CONTAINER(sp.getList(), std::list<int>)

		PRINT(BLUE "addNumber(42)" STOPC);
		TRY_F(sp.addNumber(42), " ==>fail")

		PRINT("");

		PRINT_CONTAINER(sp.getList(), std::list<int>)
		PRINT(BLUE "shortestSpan" STOPC);
		std::cout << sp.shortestSpan() << std::endl;

		PRINT(BLUE "longestSpan" STOPC);
		std::cout << sp.longestSpan() << std::endl;
	}
	return 0;
}