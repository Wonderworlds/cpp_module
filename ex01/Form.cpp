/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 23:08:46 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/07 20:11:21 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

Form::Form(void) : _name("default"), _isSigned(false), _gradeToSign(1), _gradeToExe(1)
{
	DEBUG_LOG("Form: Default Constructor called");
	return;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExe(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

Form::Form(Form const &src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExe(src._gradeToExe)
{
	DEBUG_LOG("Form: Copy Constructor called");
	return;
}

Form::~Form(void)
{
	DEBUG_LOG("Form: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

#ifndef __GNUC__
#pragma region Accessor
#endif

std::string const &Form::getName(void) const
{
	DEBUG_LOG("Form: getName function member called");

	return this->_name;
}

bool const &Form::getIsSigned(void) const
{
	DEBUG_LOG("Form: getIsSigned function member called");

	return this->_isSigned;
}

unsigned int const &Form::getGradeToSign(void) const
{
	DEBUG_LOG("Form: getGradeToSign function member called");

	return this->_gradeToSign;
}

unsigned int const &Form::getGradeToExe(void) const
{
	DEBUG_LOG("Form: getGradeToExe function member called");

	return this->_gradeToExe;
}

#ifndef __GNUC__
#pragma endregion Accessor
#endif

void Form::beSigned(Bureaucrat const &bur)
{
	DEBUG_LOG("Form: beSigned function member called");

	if (bur.getGrade() <= this->_gradeToSign)
		this->_isSigned = true;
	else
		throw GradeTooLowException();
	return;
}

Form &Form::operator=(Form const &rhs)
{
	DEBUG_LOG("Form: Assignment operator called");

	if (this != &rhs)
	{
		this->_isSigned = rhs.getIsSigned();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Form const &rhs)
{
	o << "form:\t" << rhs.getName()
	  << "\n\t| is signed: " << ((rhs.getIsSigned()) ? "true" : "false")
	  << "\n\t| grade to sign: " << rhs.getGradeToSign()
	  << "\n\t| grade to exe: " << rhs.getGradeToExe();
	return o;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too damn High!");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too damn Low!");
}
