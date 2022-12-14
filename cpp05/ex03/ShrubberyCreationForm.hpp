/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 02:28:14 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/07 20:22:38 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string const _target;

public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	virtual ~ShrubberyCreationForm(void);

	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

	std::string const &getTarget(void) const;
	virtual void execute(Bureaucrat const &executor) const;
	static AForm *make(std::string const &target);
	class ConstructionNotAllowedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif