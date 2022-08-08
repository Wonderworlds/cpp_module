/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:34:10 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/08 15:23:45 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <iterator>
# include <ccstddef>

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
	#define DEBUG_LOG(A) PRINT(A)
#else
	#define DEBUG_LOG(A)
#endif


template <typename T>
class MutantStack : public std::stack<T>
{
	typedef typename std::stack<T>::container_type::iterator				iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator		r_iterator;
	typedef typename std::stack<T>::container_type::const_iterator 			c_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator	cr_iterator;

public:
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

template <typename T>
MutantStack<T>::MutantStack(void) :  std::stack<T>()
{
	DEBUG_LOG("MutantStack<T>: Default constructor called");

	return ;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const & src) :  std::stack<T>(src)
{
	DEBUG_LOG("MutantStack<T>: Copy constructor called");

	return ;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
	DEBUG_LOG("MutantStack<T>: Destructor called");

	return ;
}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack<T> const & rhs)
{
	DEBUG_LOG("MutantStack<T>: assignment operator called");

	(void)rhs;
	return ;
}
#endif