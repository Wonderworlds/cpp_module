/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:33:20 by fmauguin          #+#    #+#             */
/*   Updated: 2023/09/07 13:47:14 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <cctype>

class RPN
{
private:
	std::stack<int> _rpn;
	int _calculator(int n1, int n2, char op, bool *error);
public:
	RPN(void);
	RPN(RPN const & src);
	~RPN(void);

	RPN &	operator=(RPN const & rhs);
	std::stack<int> const &getRPN(void) const;
	int	resolve(std::string const &str);
};

#endif