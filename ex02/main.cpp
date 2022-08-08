/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:33:16 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/08 12:48:23 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <MutantStack.hpp>

int main()
{
	// MutantStack<int> mstack;
	// mstack.push(49);
	// mstack.push(48);
	// std::cout << mstack.top() << std::endl;
	// mstack.pop();
	// std::cout << mstack.size() << std::endl;
	// mstack.push(3);
	// mstack.push(5);
	// mstack.push(32);
	// //[...]
	// mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	// MutantStack<int>::iterator ite = mstack.end();
	// ++it;
	// --it;
	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }
	// std::stack<int> s(mstack);
	return 0;
}