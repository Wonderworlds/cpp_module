/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:26:21 by fmauguin          #+#    #+#             */
/*   Updated: 2023/09/07 23:16:58 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <sys/time.h>
#include <ctime>
#include <algorithm>

class PmergeMe
{
private:
	std::vector<std::pair<unsigned int, unsigned int> > _vec;
	std::list<std::pair<unsigned int, unsigned int> > _lst;
	std::deque<std::pair<unsigned int, unsigned int> > _deq;
	unsigned int _stow_away;
	bool _odd;
	bool _isNumber(std::string const &str) const;

	template <typename T, typename R, typename S>
	double _FJ_Algo(T &c_pair, R &c_temp, R &c_sort, S stowaway)
	{
		struct timeval start, end;
		long sec, usec;
		gettimeofday(&start, NULL);
		for (size_t i = 0; i < c_pair.size(); i++)
		{
			if (c_pair[i].first > c_pair[i].second)
				std::swap(c_pair[i].first, c_pair[i].second);
		}

		for (size_t i = 0; i < c_pair.size(); i++)
			c_sort.push_back(c_pair[i].first);

		for (size_t i = 0; i < c_pair.size(); i++)
			c_temp.push_back(c_pair[i].second);

		std::sort(c_sort.begin(), c_sort.end());

		for (size_t i = 0; i < c_temp.size(); i++)
			c_sort.insert(std::lower_bound(c_sort.begin(), c_sort.end(), c_temp[i]), c_temp[i]);
		if (stowaway >= 0)
			c_sort.insert(std::lower_bound(c_sort.begin(), c_sort.end(), stowaway), stowaway);
		gettimeofday(&end, NULL);
		sec = end.tv_sec - start.tv_sec;
		if (sec < 0)
			sec += 60;
		usec = end.tv_usec - start.tv_usec;
		if (usec < 0)
			usec += 1000000;
		return ((sec / 1000000) + usec);
	}

public:
	PmergeMe(void);
	PmergeMe(PmergeMe const &src);
	~PmergeMe(void);

	PmergeMe &operator=(PmergeMe const &rhs);

	bool init(char **tab, size_t size);
	void solve(void);
};

#endif