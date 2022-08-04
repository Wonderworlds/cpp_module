/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:50:14 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/04 13:38:00 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("formulaire de demande de robotomie", 72, 45), _target("empty")
{
	DEBUG_LOG("RobotomyRequestForm: Default Constructor called");
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("formulaire de demande de robotomie", 72, 45), _target(target)
{
	DEBUG_LOG("RobotomyRequestForm: Parametric Constructor called");
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src)
{
	DEBUG_LOG("RobotomyRequestForm: Copy Constructor called");
	*this = src;

	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	DEBUG_LOG("RobotomyRequestForm: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

std::string const &RobotomyRequestForm::getTarget(void) const
{
	DEBUG_LOG("RobotomyRequestForm: getTarget function member called");
	return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	DEBUG_LOG("RobotomyRequestForm: execute function member called");
	if (executor.getGrade() > this->getGradeToExe())
		throw GradeTooLowException();
	if (this->getIsSigned() == false)
		throw FormNotSignedException();
	PRINT("* Drilling Noises *");
	if (std::rand() % 2)
		PRINT(this->_target << " has been robotomized with success");
	else
		PRINT("Such a shame, this operation is a failure");
	return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	DEBUG_LOG("RobotomyRequestForm: Assignment operator called");

	if (this != &rhs)
		this->_target = rhs.getTarget();
	return *this;
}

AForm *RobotomyRequestForm::make(std::string const &target)
{
	DEBUG_LOG("RobotomyRequestForm: make function non member called");
	RobotomyRequestForm *ptr = new (std::nothrow) RobotomyRequestForm(target);

	if (!ptr)
		throw Intern::NoPapersException();
	return ptr;
}
