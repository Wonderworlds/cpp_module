/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:09:05 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/04 13:44:27 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#define NB_FORM 3

class Intern
{
private:
	static AForm *(*f_make[NB_FORM])(std::string const &target);
	static const std::string formTab[NB_FORM];

public:
	Intern(void);
	Intern(Intern const &src);
	~Intern(void);

	Intern &operator=(Intern const &rhs);
	AForm *makeForm(std::string const &formName, std::string const &target) const;
	class NoPapersException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Not enough paper in this printer! (fail alloc)");
		}
	};
};

#endif