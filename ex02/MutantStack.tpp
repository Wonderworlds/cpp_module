/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:53:31 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/08 16:56:48 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

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

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin(void)
{
	DEBUG_LOG("MutantStack<T>: begin function member called");
	return (this->c.begin());
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::begin(void) const
{
	DEBUG_LOG("MutantStack<T>: begin const function member called");
	return (this->c.begin());
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rbegin(void)
{
	DEBUG_LOG("MutantStack<T>: rbegin function member called");
	return (this->c.rbegin());
}

template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::rbegin(void) const
{
	DEBUG_LOG("MutantStack<T>: rbegin const function member called");
	return (this->c.rbegin());
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end(void)
{
	DEBUG_LOG("MutantStack<T>: end function member called");
	return (this->c.end());
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::end(void) const
{
	DEBUG_LOG("MutantStack<T>: end const function member called");
	return (this->c.end());
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rend(void)
{
	DEBUG_LOG("MutantStack<T>: rend function member called");
	return (this->c.rend());
}

template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::rend(void) const
{
	DEBUG_LOG("MutantStack<T>: rend const function member called");
	return (this->c.rend());
}