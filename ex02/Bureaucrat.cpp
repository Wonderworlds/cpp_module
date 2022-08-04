/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:19:43 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/04 01:55:16 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	DEBUG_LOG("Bureaucrat: Default Constructor called");
	return;
}

Bureaucrat::Bureaucrat(std::string const &name, unsigned int const &grade) : _name(name)
{
	DEBUG_LOG("Bureaucrat: Parametric Constructor called");
	if (grade == 0)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	DEBUG_LOG("Bureaucrat: Copy Constructor called");
	*this = src;

	return;
}

Bureaucrat::~Bureaucrat(void)
{
	DEBUG_LOG("Bureaucrat: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

std::string const &Bureaucrat::getName() const
{
	DEBUG_LOG("Bureaucrat: getName function member called");
	return this->_name;
}

unsigned int Bureaucrat::getGrade() const
{
	DEBUG_LOG("Bureaucrat: getGrade function member called");
	return this->_grade;
}

void Bureaucrat::promote(void)
{
	DEBUG_LOG("Bureaucrat: promote function member called");
	if (this->_grade == 1)
		throw GradeTooHighException();
	this->_grade--;
	return;
}

void Bureaucrat::demote(void)
{
	DEBUG_LOG("Bureaucrat: demote function member called");
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade++;
	return;
}

void Bureaucrat::signForm(AForm &f) const
{
	DEBUG_LOG("Bureaucrat: signAForm function member called");

	try
	{
		f.beSigned(*this);
		PRINT(this->_name << " signed " << f.getName());
	}
	catch (std::exception &e)
	{
		PRINT(this->_name << " couldn't sign " << f.getName() << " because " << e.what());
	}
	return;
}

void Bureaucrat::executeForm(AForm const &form) const
{
	DEBUG_LOG("Bureaucrat: executeAForm function member called");
	try
	{
		form.execute(*this);
		PRINT(this->_name << " executed " << form.getName());
	}
	catch (std::exception &e)
	{
		PRINT(this->_name << " couldn't execute " << form.getName() << " because " << e.what());
	}
	return;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	DEBUG_LOG("Bureaucrat: Assignement operator called");

	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << rhs.getName() << " , bureaucrat grade " << rhs.getGrade();
	return o;
}