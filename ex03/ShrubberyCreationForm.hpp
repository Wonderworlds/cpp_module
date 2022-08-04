/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 02:28:14 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/04 14:42:10 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
protected:
	std::string _target;

public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

	std::string const &getTarget(void) const;
	virtual void execute(Bureaucrat const &executor) const;
	static AForm *make(std::string const &target);
	class ConstructionNotAllowedException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Construction permission denied");
		}
	};
};

#endif