/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:33:20 by fmauguin          #+#    #+#             */
/*   Updated: 2023/09/07 00:32:33 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>

class RPN
{
private:
	std::stack<int> _rpn;
	std::string		_str;
	int _calculator(int n1, int n2, char op) const;
	int	_resolve(void);
public:
	RPN(void);
	RPN(std::string const &str);
	RPN(RPN const & src);
	~RPN(void);

	RPN &	operator=(RPN const & rhs);
	std::string const &getStr(void) const;
	void setStr(std::string const &str);
};

#endif