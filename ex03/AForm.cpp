/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 23:08:46 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/07 20:14:00 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

AForm::AForm(void) : _name("default"), _isSigned(false), _gradeToSign(1), _gradeToExe(1)
{
	DEBUG_LOG("AForm: Default Constructor called");
	return;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExe(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm const &src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExe(src._gradeToExe)
{
	DEBUG_LOG("AForm: Copy Constructor called");
	return;
}

AForm::~AForm(void)
{
	DEBUG_LOG("AForm: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

#ifndef __GNUC__
#pragma region Accessor
#endif

std::string const &AForm::getName(void) const
{
	DEBUG_LOG("AForm: getName function member called");

	return this->_name;
}

bool const &AForm::getIsSigned(void) const
{
	DEBUG_LOG("AForm: getIsSigned function member called");

	return this->_isSigned;
}

unsigned int const &AForm::getGradeToSign(void) const
{
	DEBUG_LOG("AForm: getGradeToSign function member called");

	return this->_gradeToSign;
}

unsigned int const &AForm::getGradeToExe(void) const
{
	DEBUG_LOG("AForm: getGradeToExe function member called");

	return this->_gradeToExe;
}

#ifndef __GNUC__
#pragma endregion Accessor
#endif

void AForm::beSigned(Bureaucrat const &bur)
{
	DEBUG_LOG("AForm: beSigned function member called");

	if (bur.getGrade() <= this->_gradeToSign)
		this->_isSigned = true;
	else
		throw GradeTooLowException();
	return;
}

AForm &AForm::operator=(AForm const &rhs)
{
	DEBUG_LOG("AForm: Assignment operator called");

	if (this != &rhs)
	{
		this->_isSigned = rhs.getIsSigned();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, AForm const &rhs)
{
	o << "form:\t" << rhs.getName()
	  << "\n\t| is signed: " << ((rhs.getIsSigned()) ? "true" : "false")
	  << "\n\t| grade to sign: " << rhs.getGradeToSign()
	  << "\n\t| grade to exe: " << rhs.getGradeToExe();
	return o;
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too damn High!");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too damn Low!");
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("Where's the signature!");
}