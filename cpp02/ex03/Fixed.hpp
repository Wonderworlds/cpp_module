/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 14:14:31 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/31 20:54:30 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int					_value;
	static int const	_bits = 8;
public:
	Fixed(void);
	Fixed(int const newValue);
	Fixed(float const newValue);
	Fixed(Fixed const & src);
	~Fixed(void);

	Fixed &	operator=(Fixed const & rhs);

	bool	operator>(Fixed const & rhs) const;
	bool	operator<(Fixed const & rhs) const;
	bool	operator>=(Fixed const & rhs) const;
	bool	operator<=(Fixed const & rhs) const;
	bool	operator==(Fixed const & rhs) const;
	bool	operator!=(Fixed const & rhs) const;

	Fixed	operator+(Fixed const & rhs) const;
	Fixed	operator-(Fixed const & rhs) const;
	Fixed	operator*(Fixed const & rhs) const;
	Fixed	operator/(Fixed const & rhs) const;

	Fixed &	operator++(void);
	Fixed operator++(int);
	Fixed &	operator--(void);
	Fixed operator--(int);

	static Fixed &	min(Fixed &f1, Fixed &f2);
	static const Fixed &	min(Fixed const &f1, Fixed const &f2);
	static Fixed &	max(Fixed &f1, Fixed &f2);
	static const Fixed &	max(Fixed const &f1, Fixed const &f2);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);

#endif