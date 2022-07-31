/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 14:14:31 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/31 15:45:55 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int					_value;
	static int const	_bits;
public:
	Fixed(void);
	Fixed(int const newValue);
	Fixed(Fixed const & src);
	~Fixed(void);

	Fixed &	operator=(Fixed const & rhs);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

};

#endif