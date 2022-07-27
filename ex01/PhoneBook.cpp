/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:16:37 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/27 23:30:35 by fmauguin         ###   ########.fr       */
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

void	PhoneBook::setcontact(void) {
	std::string	str;

	if (this->_index == 8)
		this->_index = 0;
	std::cout << "\033[H\033[2J\033[3J";
	std::cout << "Create contact" << std::endl;
	std::cout << "First name: ";
	std::getline (std::cin,str);
	this->_contacts[this->_index].setfirstname(str);
	std::cout << "Last name: ";
	std::getline (std::cin,str);
	this->_contacts[this->_index].setlastname(str);
	std::cout << "Nickname: ";
	std::getline (std::cin,str);
	this->_contacts[this->_index].setnickname(str);
	std::cout << "Phone number: ";
	std::getline (std::cin,str);
	this->_contacts[this->_index].setphonenumber(str);
	std::cout << "Darkest secret: ";
	std::getline (std::cin,str);
	this->_contacts[this->_index].setsecret(str);
	this->_index++;
	if (this->_size < 8)
		this->_size++;
}