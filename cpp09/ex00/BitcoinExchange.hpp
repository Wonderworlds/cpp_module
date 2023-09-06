/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:46:52 by fmauguin          #+#    #+#             */
/*   Updated: 2023/09/06 18:00:57 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <list>
#include <string>

class BitcoinExchange
{
private:
	std::list<std::pair<std::string, float> > file;

	int _DateFormat(std::string const &date) const;
	int _StrIsNumber(std::string const &str, bool dec) const;
	int _CompareDate(std::string const &d1, std::string const &d2) const;
	void _AddToList(std::string const &str);
	double _GetBitcoinRate(std::string const &date) const;

public:
	BitcoinExchange(void);
	BitcoinExchange(char *file);
	BitcoinExchange(BitcoinExchange const &src);
	~BitcoinExchange(void);

	BitcoinExchange &operator=(BitcoinExchange const &rhs);
	int SetFile(char const *file);
	void PrintList(void) const;
	std::list<std::pair<std::string, float> >getFile(void) const;
};

#endif