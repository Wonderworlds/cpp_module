/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:16:37 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/27 23:46:55 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(void) {
	this->_index = 0;
	this->_size = 0;
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

const Contact	*PhoneBook::getcontact(int index) const {
	if (index < 0 || index > 7)
		return NULL;
	return (&this->_contacts[index]);
}

int	PhoneBook::getsize(void) const{
	return (this->_size);
}

static std::string	get_field(const char *field) {
	std::string	ret;

	std::cout << field;
	std::getline (std::cin,ret);
	while (ret.empty())
	{
		std::cout << "\033[A\33[2K\r" << "Error input empty | " << field;
		std::getline (std::cin,ret);
	}
	return (ret);
}

void	PhoneBook::setcontact(void) {
	std::string	str;

	if (this->_index == 8)
		this->_index = 0;
	std::cout << "\033[H\033[2J\033[3J";
	std::cout << "Create contact" << std::endl;
	str = get_field("First name: ");
	this->_contacts[this->_index].setfirstname(str);
	str = get_field("Last name: ");
	this->_contacts[this->_index].setlastname(str);
	str = get_field("Nickname: ");
	this->_contacts[this->_index].setnickname(str);
	str = get_field("Phone number: ");
	this->_contacts[this->_index].setphonenumber(str);
	str = get_field("Darkest secret: ");
	this->_contacts[this->_index].setsecret(str);
	this->_index++;
	if (this->_size < 8)
		this->_size++;
}