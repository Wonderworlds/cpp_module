/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:05:02 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/04 00:06:21 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

class Form;

class Bureaucrat
{
private:
	std::string _name;
	unsigned int _grade;

public:
	Bureaucrat(void);
	Bureaucrat(std::string const &name, unsigned int const &grade);
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat(void);

	Bureaucrat &operator=(Bureaucrat const &rhs);

	std::string const &getName() const;
	unsigned int getGrade() const;

	void promote();
	void demote();
	void signForm(Form &f) const;
	void executeForm(Form const &form) const;

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what(void) const throw()
		{
			return ("Grade is too damn High!");
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what(void) const throw()
		{
			return ("Grade is too damn Low!");
		}
	};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif