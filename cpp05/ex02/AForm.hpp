/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 23:00:56 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/07 20:13:41 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string const _name;
	bool _isSigned;
	unsigned int const _gradeToSign;
	unsigned int const _gradeToExe;

public:
	AForm(void);
	AForm(const std::string &name, int gradeToSign, int gradeToExec);
	AForm(AForm const &src);
	virtual ~AForm(void);

	AForm &operator=(AForm const &rhs);

	std::string const &getName() const;
	bool const &getIsSigned() const;
	unsigned int const &getGradeToSign() const;
	unsigned int const &getGradeToExe() const;
	void beSigned(Bureaucrat const &bur);
	virtual void execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, AForm const &rhs);

#endif