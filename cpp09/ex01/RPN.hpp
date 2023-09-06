/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:33:20 by fmauguin          #+#    #+#             */
/*   Updated: 2023/09/06 20:34:14 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <fstream>
# include <deque>

class RPN
{
private:
	std::deque<char> rpn;
	int	_SetRPN(std::string const &rpn);
public:
	RPN(void);
	RPN(std::string const &rpn);
	RPN(RPN const & src);
	~RPN(void);

	RPN &	operator=(RPN const & rhs);
	std::deque<char> const &GetValue(void) const;
};

#endif