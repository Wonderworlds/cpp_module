/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:33:16 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/09 14:24:46 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <list>
#include <vector>
#include <algorithm>
#include <MutantStack.hpp>
#include <ctime>
#include <cstdlib>

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

#define TERN_OK(A) ((A) ? GREEN "OK" STOPC : RED "KO" STOPC)

int main()
{
	int save1;
	unsigned int save2;
	{
		TITLE("MANDATORY");
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		save1 = mstack.top();
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		save2 = mstack.size();
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		{
			TITLE("Test copy");
			while (!s.empty())
			{
				std::cout << s.top() << "\t| " << mstack.top() << "\t| " << TERN_OK(s.top() == mstack.top()) << std::endl;
				mstack.pop();
				s.pop();
			}
		}
		TITLE("Test mandatory other containers");
		std::list<int> lst;
		std::vector<int> vec;
		lst.push_back(5);
		vec.push_back(5);
		lst.push_back(17);
		vec.push_back(17);
		PRINT("list<int>: " << lst.back() << "\t| vector<int>: " << vec.back() << "\t| " << TERN_OK(lst.back() == save1 && vec.back() == save1));
		lst.pop_back();
		vec.pop_back();
		PRINT("list<int>: " << lst.size() << "\t| vector<int>: " << vec.size() << "\t| " << TERN_OK(lst.size() == save2 && vec.size() == save2));
		lst.push_back(3);
		vec.push_back(3);
		lst.push_back(5);
		vec.push_back(5);
		lst.push_back(737);
		vec.push_back(737);
		//[...]
		lst.push_back(0);
		vec.push_back(0);
		PRINT(BLUE "\ntest iterator");
		for (it = mstack.begin(); it != ite; it++)
			lst.push_back(*it);
		it = mstack.begin();
		std::list<int>::iterator itL = lst.begin();
		std::vector<int>::iterator itV = vec.begin();
		++itL;
		++itV;
		--itV;
		--itL;
		PRINT(BLUE << std::setw(7) << "LIST"
				   << "   " << std::setw(7) << "VECTOR"
				   << "   " << std::setw(7) << "MSTACK"
				   << "   " STOPC);

		while (it != ite)
		{
			PRINT(std::setw(7) << *itL
							   << " | " << std::setw(7) << *itV
							   << " | " << std::setw(7) << *it
							   << " | " << TERN_OK(*it == *itV && *it == *itL));
			++it;
			++itV;
			++itL;
		}
	}
	{
		TITLE("Tests random");
		int rdm;
		MutantStack<int> n_stack;
		std::vector<int> vec;
		std::list<int> lst;
		srand(time(NULL));
		for (size_t i = 0; i < 20; i++)
		{
			rdm = rand() % 1000000;
			n_stack.push(rdm);
			lst.push_back(rdm);
			vec.push_back(rdm);
		}
		std::vector<int>::iterator itv = vec.begin();
		std::list<int>::iterator itl = lst.begin();
		PRINT(BLUE << std::setw(7) << "LIST"
				   << "   " << std::setw(7) << "VECTOR"
				   << "   " << std::setw(7) << "MSTACK"
				   << "   " STOPC);

		for (MutantStack<int>::iterator it = n_stack.begin(); it != n_stack.end(); it++)
		{
			PRINT(std::setw(7) << *itl
							   << " | " << std::setw(7) << *itv
							   << " | " << std::setw(7) << *it
							   << " | " << TERN_OK(*it == *itv && *it == *itl));
			itv++;
			itl++;
			/* code */
		}
	}
	return 0;
}