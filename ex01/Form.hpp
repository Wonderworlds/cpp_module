/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 23:00:56 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/07 20:11:31 by fmauguin         ###   ########.fr       */
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
	Form(const std::string &name, int gradeToSign, int gradeToExec);
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
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif