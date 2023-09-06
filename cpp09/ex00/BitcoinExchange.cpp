/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:46:57 by fmauguin          #+#    #+#             */
/*   Updated: 2023/09/06 22:59:20 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "cstdlib"

#define PRINT(A) std::cout << A << std::endl

#define MAX_YEAR 2023
#define DB "data.csv"

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

int BitcoinExchange::_compareDate(std::string const &d1, std::string const &d2) const
{
	int ymd1[3];
	int ymd2[3];
	std::string y[2];
	std::string m[2];
	std::string d[2];
	if (d1 == d2)
		return 1;
	else
	{
		y[0] = d1.substr(0, 4);
		y[1] = d2.substr(0, 4);
		ymd1[0] = std::atoi(y[0].c_str());
		ymd2[0] = std::atoi(y[1].c_str());
		if (ymd1[0] > ymd2[0])
			return 2;
		else if (ymd1[0] < ymd2[0])
			return 0;
		m[0] = d1.substr(5, 2);
		m[1] = d2.substr(5, 2);
		ymd1[1] = std::atoi(m[0].c_str());
		ymd2[1] = std::atoi(m[1].c_str());
		if (ymd1[1] > ymd2[1])
			return 2;
		else if (ymd1[1] < ymd2[1])
			return 0;
		d[0] = d1.substr(8, 2);
		d[1] = d2.substr(8, 2);
		ymd1[2] = std::atoi(d[0].c_str());
		ymd2[2] = std::atoi(d[1].c_str());
		if (ymd1[2] > ymd2[2])
			return 2;
	}
	return 0;
}

double BitcoinExchange::_getBitcoinRate(std::string const &date) const
{
	std::map<std::string, float>::const_iterator it;
	int compare;
	it = _db.begin();
	while (it != _db.end())
	{
		compare = _compareDate(it->first, date);
		if (compare > 0)
		{
			if (it == _db.begin())
				return -1;
			else if (compare == 1)
				return it->second;
			else
				return (--it)->second;
		}
		else
		it++;
	}
	return -1;
}

int BitcoinExchange::_strIsNumber(std::string const &str, bool dec) const
{

	std::string::const_iterator it;
	bool point;

	point = false;
	it = str.begin();
	if (*it == '-')
		it++;
	while (it != str.end())
	{
		if (*it <= '9' && *it >= '0')
			it++;
		else
			return 0;
		if (dec && (*it == '.' && !point))
		{
			point = true;
			it++;
		}
	}
	return 1;
}

int BitcoinExchange::_strIsDate(std::string const &date) const
{
	int ymd[3];
	std::string y;
	std::string m;
	std::string d;

	if (!(date[4] == '-' && date[7] == '-'))
		return 1;
	y = date.substr(0, 4);
	m = date.substr(5, 2);
	d = date.substr(8, 2);
	if (!_strIsNumber(y, 0) || !_strIsNumber(m, 0) || !_strIsNumber(d, 0))
		return 0;
	ymd[0] = std::atoi(y.c_str());
	if (ymd[0] > MAX_YEAR)
		return 0;
	ymd[1] = std::atoi(m.c_str());
	if (ymd[1] > 12)
		return 0;
	ymd[2] = std::atoi(d.c_str());
	if (ymd[2] > 31 || (ymd[2] > 29 && ymd[1] == 2) || (ymd[2] > 30 && (ymd[1] == 4 || ymd[1] == 6 || ymd[1] == 9 || ymd[1] == 11)))
		return 0;
	return 1;
}

int BitcoinExchange::setFile(std::string const &file)
{
	std::ifstream f;
	std::string line;

	f.open(file.c_str(), std::ifstream::in);
	if (f.fail())
	{
		PRINT("Error: File couldn't open!");
		return 1;
	}
	std::getline(f, line);
	if (line == "date | value")
		std::getline(f, line);
	while (!f.eof())
	{
		_parseLineFile(line, " | ", 3);
		std::getline(f, line);
	}
	_parseLineFile(line, " | ", 3);
	f.close();
	return 0;
}

#ifndef __GNUC__
#pragma region Constructor && Destructor
#endif

BitcoinExchange::BitcoinExchange(void)
{
	DEBUG_LOG("BitcoinExchange: Default Constructor called");
	return;
}

BitcoinExchange::BitcoinExchange(std::map<std::string, float> const &db) : _db(db)
{
	DEBUG_LOG("BitcoinExchange: Parametric Constructor called");
	return;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	DEBUG_LOG("BitcoinExchange: Copy Constructor called");
	*this = src;
	return;
}

BitcoinExchange::~BitcoinExchange(void)
{
	DEBUG_LOG("BitcoinExchange: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	DEBUG_LOG("BitcoinExchange: Assignement operator called");

	if (this != &rhs)
		this->_db = rhs.getDB();
	return *this;
}

std::map<std::string, float> BitcoinExchange::getDB(void) const
{
	return this->_db;
}

void BitcoinExchange::_parseLineDB(std::string const &line, const char *sep, const size_t sepSize)
{
	size_t sepPos;
	std::string date;
	std::string value;

	sepPos = line.find(sep);
	if (sepPos != std::string::npos)
	{
		date = line.substr(0, sepPos);
		if (!_strIsDate(date))
			return;
		value = line.substr(sepPos + sepSize, line.size() - sepPos);
		if (!_strIsNumber(value, true))
			return;
	}
	this->_db[date.c_str()] = std::atof(value.c_str());
}

void BitcoinExchange::_parseLineFile(std::string const &line, const char *sep, const size_t sepSize)
{
	size_t sepPos;
	std::string date;
	std::string value;
	float valuef;
	double rate;

	sepPos = line.find(sep);
	if (sepPos != std::string::npos)
	{
		date = line.substr(0, sepPos);
		if (!_strIsDate(date))
		{
			PRINT("Error: bad input => " << line);
			return;
		}
		value = line.substr(sepPos + sepSize, line.size() - sepPos);
		if (!_strIsNumber(value, true))
		{
			PRINT("Error: bad input => " << line);
			return;
		}
		valuef = std::atof(value.c_str());
		if (valuef < 0)
			PRINT("Error: not a positive number.");
		else if (valuef > 1000)
			PRINT("Error: too large a number.");
		else
		{
			rate = _getBitcoinRate(date);
			if (rate == -1)
				PRINT("Error: No Match in DB => " << line);
			else
				PRINT(date <<  " => " << value << " = " << (rate * valuef));
		}
	}
	else
		PRINT("Error: bad input => " << line);
}

int BitcoinExchange::initDB(std::string const &dbFile)
{
	std::ifstream dbStream;
	std::string line;

	dbStream.open(dbFile.c_str(), std::istream::in);
	if (dbStream.fail())
	{
		PRINT("Error: file database.");
		return 1;
	}
	while (!dbStream.eof())
	{
		std::getline(dbStream, line);
		_parseLineDB(line, ",", 1);
	}
	return 0;
}