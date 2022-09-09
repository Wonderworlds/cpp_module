/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:20:05 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/05 16:10:07 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
	#define DEBUG_LOG(A) PRINT(A)
#else
	#define DEBUG_LOG(A)
#endif


Base * makeA(void) { return (new (std::nothrow) A());}
Base * makeB(void) { return (new (std::nothrow) B());}
Base * makeC(void) { return (new (std::nothrow) C());}

Base * generate(void)
{
	Base *(*f_make[3])(void) = {makeA, makeB, makeC};
	const char type[3] = {'A', 'B', 'C'};
	int random_variable = std::rand() % 3;

	PRINT("TYPE START: " << type[random_variable]);
	return (f_make[random_variable]());
}

void identify(Base* p)
{
	A *a;
	B *b;

	if ((a = dynamic_cast<A *>(p)))
		PRINT("type * = A");
	else if ((b = dynamic_cast<B *>(p)))
		PRINT("type * = B");
	else
		PRINT("type * = C");
	return ;
}


void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		PRINT("type & = A");
	}
	catch (const std::exception &e)
	{
		(void)e;
		try
		{
			B &b= dynamic_cast<B&>(p);
			(void)b;
			PRINT("type & = B");
		}
		catch (const std::exception &d)
		{
			(void)d;
			PRINT("type & = C");
		}
	}
	return ;
}

int main(void)
{
 	std::srand(std::time(NULL));
	Base *ptr;
	int i = 10;

	while (i--)
	{
		ptr = generate();
		if (ptr)
		{
			identify(ptr);
			identify(*ptr);
			delete ptr;
		}
		PRINT("");
	}
	return (0);
}
