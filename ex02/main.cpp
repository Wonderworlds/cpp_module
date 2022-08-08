/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:33:16 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/08 17:14:55 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <list>
#include <vector>
#include <algorithm>
#include <MutantStack.hpp>


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

int main()
{
	int save1;
	unsigned int save2;

	TITLE("MANDATORY");
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	save1 = mstack.top();
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	save2 = mstack.size();
	std::cout << mstack.size() << std::endl;
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

	MutantStack<int> n_stack(mstack);
	for (it = mstack.begin(); it != ite; it++)
		n_stack.push(*it);
	TITLE("LIST");
	{
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << lst.back() << "\t| " << ((lst.back() == save1) ? GREEN"OK"STOPC : RED"KO"STOPC) << std::endl;
		lst.pop_back();
		std::cout << lst.size() << "\t| " << ((lst.size() == save2) ? GREEN"OK"STOPC : RED"KO"STOPC) << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		//[...]
		lst.push_back(0);
		PRINT(BLUE "\ntest iterator");
		for (it = mstack.begin(); it != ite; it++)
			lst.push_back(*it);
		it = n_stack.begin();
		std::list<int>::iterator itS = lst.begin();
		std::list<int>::iterator iteS = lst.end();
		++itS;
		--itS;
		while (itS != iteS)
		{
			std::cout << *itS << "\t| " << ((*it == *itS) ? GREEN"OK"STOPC : RED"KO"STOPC) << std::endl;
			++it;
			++itS;
		}
	}
	TITLE("VECTOR");
	{
		std::vector<int> vec;
		vec.push_back(5);
		vec.push_back(17);
		std::cout << vec.back() << "\t| " << ((vec.back() == save1) ? GREEN"OK"STOPC : RED"KO"STOPC) << std::endl;
		vec.pop_back();
		std::cout << vec.size() << "\t| " << ((vec.size() == save2) ? GREEN"OK"STOPC : RED"KO"STOPC) << std::endl;
		vec.push_back(3);
		vec.push_back(5);
		vec.push_back(737);
		//[...]
		vec.push_back(0);
		PRINT(BLUE "\ntest iterator");
		for (it = mstack.begin(); it != ite; it++)
			vec.push_back(*it);
		it = n_stack.begin();
		std::vector<int>::iterator itS = vec.begin();
		std::vector<int>::iterator iteS = vec.end();
		++itS;
		--itS;
		while (itS != iteS)
		{
			std::cout << *itS << "\t| " << ((*it == *itS) ? GREEN"OK"STOPC : RED"KO"STOPC) << std::endl;
			++it;
			++itS;
		}
	}
	return 0;
}