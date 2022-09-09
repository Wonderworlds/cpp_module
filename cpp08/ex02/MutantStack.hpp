/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:34:10 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/08 16:54:28 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <iterator>

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
	#define DEBUG_LOG(A) PRINT(A)
#else
	#define DEBUG_LOG(A)
#endif


template <typename T>
class MutantStack : public std::stack<T>
{

public:
	typedef typename std::stack<T>::container_type::iterator				iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator		r_iterator;
	typedef typename std::stack<T>::container_type::const_iterator 			c_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator	cr_iterator;
	MutantStack<T>(void);
	MutantStack<T>(MutantStack<T> const & src);
	virtual ~MutantStack<T>(void);

	iterator begin();
	c_iterator begin() const;
	r_iterator rbegin();
	cr_iterator rbegin() const;
	iterator end();
	c_iterator end() const;
	r_iterator rend();
	cr_iterator rend() const;
	MutantStack<T> &	operator=(MutantStack<T> const & rhs);
};

#include <MutantStack.tpp>

#endif