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

int	CompareDate(std::string d1, std::string d2)
{
	int	ymd1[3];
	int	ymd2[3];
	std::string	y[2];
	std::string	m[2];
	std::string	d[2];
	if (d1 == d2)
		return 1;
	else
	{
		y[0] =  d1.substr(0, 4);
		y[1] =  d2.substr(0, 4);
		ymd1[0] = std::atoi(y[0].c_str());
		ymd2[0] = std::atoi(y[1].c_str());
		if (ymd1[0] > ymd2[0])
			return 2;
		else if (ymd1[0] < ymd2[0])
			return 0;
		m[0] =  d1.substr(5, 2);
		m[1] =  d2.substr(5, 2);
		ymd1[1] = std::atoi(m[0].c_str());
		ymd2[1] = std::atoi(m[1].c_str());
		if (ymd1[1] > ymd2[1])
			return 2;
		else if (ymd1[1] < ymd2[1])
			return 0;
		d[0] =  d1.substr(8, 2);
		d[1] =  d2.substr(8, 2);
		ymd1[2] = std::atoi(d[0].c_str());
		ymd2[2] = std::atoi(d[1].c_str());
		if (ymd1[2] > ymd2[2])
			return 2;
	}
	return 0;
}

double	BitcoinExchange::_GetBitcoinRate(std::string date) const {
	std::ifstream							f;
	char									c;
	std::pair<std::string, std::string> 	p;
	std::pair<std::string, std::string> 	lastp;
	int										compare;
	f.open(DB, std::ifstream::in);
	if (f.fail())
	{
		PRINT("Error : database couldn't open!");
		return 1;
	}
	c = f.get();
	while (f.good())
	{
		while (c != ',')
		{
			p.first += c;
			c = f.get();
			if (!f.good())
				break ;
		}
		if (c == ',')
		{
			while (c != '\n')
			{
				p.second += c;
				c = f.get();
				if (!f.good())
					break ;
			}
		}
		compare = CompareDate(p.first, date);
		if (compare > 0)
			f.close();
		if (compare == 1)
			return (std::atof(p.second.c_str()));
		else if (compare == 2 && !lastp.second.empty())
			return (std::atof(lastp.second.c_str()));
		else if (lastp.second.empty())

		lastp = p;
		p.first.clear();
		p.second.clear();
		c = f.get();
	}
	f.close();
	return 0;

}

void BitcoinExchange::printList(void) const {

	std::list<std::pair<std::string, float> >::const_iterator	itlist;
	double														match;
	itlist = this->file.begin();
	while (itlist != this->file.end())
	{
		if ((*itlist).second > 1000 || (*itlist).second < 0)
			PRINT((*itlist).first);
		else 
		{
			match = this->_GetBitcoinRate((*itlist).first);
			if (match < 0)
				PRINT("Error : No Match in DB => " << (*itlist).first << " | " << (*itlist).second);
			else
				PRINT((*itlist).first << " => " << (*itlist).second \
				<< " = " << ((*itlist).second * match));
		}
		itlist++;
	}
}

int strIsNumber(std::string str, bool dec) {

	std::string::const_iterator	it;
	bool						point;

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

int dateFormat(std::string date) {

	int	ymd[3];
	std::string	y;
	std::string	m;
	std::string	d;

	if (!(date[4] == '-' && date[7] == '-'))
		return 1;
	y =  date.substr(0, 4);
	m =  date.substr(5, 2);
	d =  date.substr(8, 2);
	if (!strIsNumber(y, 0) || !strIsNumber(m, 0) || !strIsNumber(d, 0))
		return (1);
	ymd[0] = std::atoi(y.c_str());
	if (ymd[0] > MAX_YEAR)
		return 1;
	ymd[1] = std::atoi(m.c_str());
	if (ymd[1] > 12)
		return 1;
	ymd[2] = std::atoi(d.c_str());
	if (ymd[2] > 31 || (ymd[2] > 29 && ymd[1] == 2) || (ymd[2] > 30\
		&& (ymd[1] == 4 || ymd[1] == 6 || ymd[1] == 9 || ymd[1] == 11)))
		return 1;
	return 0;
}


void BitcoinExchange::_addToList(std::string str)
{
	std::pair<std::string, float>	p;
	std::string						value;
	size_t							sep;

	if (str == "date | value" && this->file.size() == 0)
		return ;
	sep = str.find(" | ", 0);
	p.second = -1;
	if (sep == std::string::npos || sep != 10)
	{
		p.first = "Error : bad input => " + str;
		this->file.push_back(p);
		return ;
	}
	value = str.substr(sep + 3, std::string::npos);
	if (!strIsNumber(value, true))
		p.first = "Error : bad input => " + str;
	else
	{
		p.second = std::atof(value.c_str());
		if (p.second < 0)
			p.first = "Error: not a positive number.";
		else if (p.second > 1000)
			p.first = "Error: too large a number.";
		else
		{
			p.first = str.substr(0, sep);
			if (dateFormat(p.first))
			{
				p.second = -1;
				p.first = "Error: bad date => " + str;
			}
		}
	}
	this->file.push_back(p);
}

int	BitcoinExchange::setFile(char *file) {

	std::ifstream	f;
	char			c;
	std::string		str;

	f.open(file, std::ifstream::in);
	if (f.fail())
	{
		PRINT("Error : File couldn't open!");
		return 1;
	}
	c = f.get();
	while (f.good())
	{
		while (c != '\n')
		{
			str += c;
			c = f.get();
			if (!f.good())
				break ;
		}
		this->_addToList(str);
		str.clear();
		c = f.get();
	}
	f.close();
	return 0;
}

std::list<std::pair<std::string, float> >	BitcoinExchange::getFile(void) const {
	return this->file;
}

#ifndef __GNUC__
#pragma region Constructor && Destructor
#endif

BitcoinExchange::BitcoinExchange(void) {
	DEBUG_LOG("BitcoinExchange: Default Constructor called");
	return ;
}

BitcoinExchange::BitcoinExchange(char *file) {
	DEBUG_LOG("BitcoinExchange: Parametric Constructor called");
	this->setFile(file);
	return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) {
	DEBUG_LOG("BitcoinExchange: Copy Constructor called");
	*this = src;

	return ;
}

BitcoinExchange::~BitcoinExchange(void) {
	DEBUG_LOG("BitcoinExchange: Destructor called");
	return ;
}

#ifndef __GNUC__
#pragma endregion Constructor && Destructor
#endif

BitcoinExchange &	BitcoinExchange::operator=(BitcoinExchange const & rhs) {
	DEBUG_LOG("BitcoinExchange: Assignement operator called");

	if (this != &rhs)
		this->file = rhs.getFile();
	return *this;
}
