/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:41:32 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/31 20:50:53 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;
public:
	Point(void);
	Point(Fixed const x, Fixed const y);
	Point(Point const & src);
	~Point(void);

	Point &	operator=(Point const & rhs);

	Fixed const	getX(void) const;
	Fixed const	getY(void) const;
	void	setX(Fixed const x);
	void	setY(Fixed const y);

};

#endif