/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 23:00:56 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/03 23:56:29 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const _name;
	bool _isSigned;
	unsigned int const _gradeToSign;
	unsigned int const _gradeToExe;

public:
	Form(void);
	Form(Form const &src);
	~Form(void);

	Form &operator=(Form const &rhs);

	std::string const &getName() const;
	bool const &getIsSigned() const;
	unsigned int const &getGradeToSign() const;
	unsigned int const &getGradeToExe() const;
	void beSigned(Bureaucrat const &bur);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Grade is too damn High!");
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Grade is too damn Low!");
		}
	};
};

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif