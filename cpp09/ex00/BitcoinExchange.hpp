/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:46:52 by fmauguin          #+#    #+#             */
/*   Updated: 2023/09/06 17:47:57 by fmauguin         ###   ########.fr       */
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
	std::list<std::pair<std::string, float> > db;

	int _CheckFormatFile(void);
	void _addToList(std::string str);
	double _GetBitcoinRate(std::string date) const;

public:
	BitcoinExchange(void);
	BitcoinExchange(char *file);
	BitcoinExchange(BitcoinExchange const &src);
	~BitcoinExchange(void);

	BitcoinExchange &operator=(BitcoinExchange const &rhs);
	int setFile(char *file);
	void printList(void) const;
	std::list<std::pair<std::string, float> > getFile(void) const;
};

#endif