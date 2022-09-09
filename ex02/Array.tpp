/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:43:24 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/07 18:06:42 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array(void) : _array(new T[0]), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int const &n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(Array<T> const &src)
{
	this->_size = src.size();
	this->_array = new T[this->_size];
	for (size_t i = 0; i < this->_size; i++)
		this->_array[i] = src[i];
}

template <typename T>
Array<T>::~Array(void) { delete[] this->_array; }

template <typename T>
unsigned int const &Array<T>::size(void) const { return this->_size; }

template <typename T>
T &Array<T>::operator[](unsigned int const &idx) const
{
	if (idx >= this->_size)
		throw IndexOutOfBoundsException();
	return (this->_array[idx]);
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &rhs)
{
	if (this != &rhs)
	{
		this->size = rhs.size();
		delete[] this->_array;
		this->_array = new T[this->_size];
		for (size_t i = 0; i < this->size; i++)
			this->_array[i] = rhs[i];
	}
	return *this;
}

template <typename T>
const char *Array<T>::IndexOutOfBoundsException::what(void) const throw()
{
	return ("Index out of bounds");
}