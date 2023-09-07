/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:26:21 by fmauguin          #+#    #+#             */
/*   Updated: 2023/09/07 18:01:39 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <deque>
# include <vector>
# include <list>
# include <cctype>
# include <algorithm>

class PmergeMe
{
private:
	std::vector<unsigned int> _vec;
	std::list<unsigned int> _lst;
	std::deque<unsigned int> _deq;
	bool _isNumber(std::string const &str) const;
public:
	PmergeMe(void);
	PmergeMe(PmergeMe const & src);
	~PmergeMe(void);

	PmergeMe &	operator=(PmergeMe const & rhs);

	bool fillContainer(char **tab, size_t size);
	void printOutput(void) const;
};

#endif