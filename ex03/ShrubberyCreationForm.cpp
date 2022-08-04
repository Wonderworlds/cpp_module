/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:50:14 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/04 02:26:35 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <fstream>

#define ASCII_TREE "       _-_\n\
    /~~   ~~\\\n\
 /~~         ~~\\\n\
{               }\n\
  \\  _-   -_  /\n\
   ~  \\\\ //  ~\n\
_- -   | | _- _\n\
  _ -  | |   -_\n\
      // \\\\\n"

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("empty")
{
	DEBUG_LOG("ShrubberyCreationForm: Default Constructor called");
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	DEBUG_LOG("ShrubberyCreationForm: Parametric Constructor called");
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src)
{
	DEBUG_LOG("ShrubberyCreationForm: Copy Constructor called");
	*this = src;

	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	DEBUG_LOG("ShrubberyCreationForm: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

std::string const &ShrubberyCreationForm::getTarget(void) const
{
	DEBUG_LOG("ShrubberyCreationForm: getTarget function member called");
	return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	DEBUG_LOG("ShrubberyCreationForm: execute function member called");
	std::ofstream o;

	if (executor.getGrade() > this->getGradeToExe())
		throw GradeTooLowException();
	if (this->getIsSigned() == false)
		throw FormNotSignedException();
	std::string tmp = this->_target;
	o.open(tmp.append("_shrubbery").c_str(), std::ofstream::out | std::ofstream::app);
	if (o.fail())
		throw ConstructionNotAllowedException();
	o << ASCII_TREE;
	o.close();
	return;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	DEBUG_LOG("ShrubberyCreationForm: Assignment operator called");

	if (this != &rhs)
		this->_target = rhs.getTarget();
	return *this;
}

AForm *ShrubberyCreationForm::make(std::string const &target)
{
	DEBUG_LOG("ShrubberyCreationForm: make function non member called");
	ShrubberyCreationForm *ptr = new (std::nothrow) ShrubberyCreationForm(target);

	if (!ptr)
		throw Intern::NoPapersException();
	return ptr;
}
