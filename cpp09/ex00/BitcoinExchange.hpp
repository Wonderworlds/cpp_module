/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:46:52 by fmauguin          #+#    #+#             */
/*   Updated: 2023/09/06 22:55:09 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>

class BitcoinExchange
{
private:
	std::map<std::string, float> 	_db;

	int		_strIsDate(std::string const &date) const;
	int		_strIsNumber(std::string const &str, bool dec) const;
	int		_compareDate(std::string const &d1, std::string const &d2) const;
	void	 _parseLineDB(std::string const &line, const char *sep, const size_t sepSize);
	void	 _parseLineFile(std::string const &line, const char *sep, const size_t sepSize);
	double	_getBitcoinRate(std::string const &date) const;

public:
	BitcoinExchange(void);
	BitcoinExchange(std::map<std::string, float> const &db);
	BitcoinExchange(BitcoinExchange const &src);
	~BitcoinExchange(void);

	BitcoinExchange &operator=(BitcoinExchange const &rhs);
	void printOutput(void) const;
	std::map<std::string, float> getDB(void) const;
	std::string const &getFile(void) const;
	int setFile(std::string const &file);
	int	initDB(std::string const &dbFile);
};

#endif