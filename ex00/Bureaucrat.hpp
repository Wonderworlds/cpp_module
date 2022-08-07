/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:05:02 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/07 20:09:12 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

class Bureaucrat
{
private:
	std::string const _name;
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
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif