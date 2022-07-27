/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:16:37 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/27 20:40:51 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(void) {
	this->index = 0;
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

Contact	*PhoneBook::getcontact(int index) {
	if (index < 0 || index > 7)
		return NULL;
	return (&this->_contacts[index]);
}

void	PhoneBook::setcontact(void) {
	std::string	str;

	if (this->index == 8)
		this->index = 0;
	std::cout << "\033[H\033[2J\033[3J";
	std::cout << "Create contact" << std::endl;
	std::cout << "First name: ";
	std::getline (std::cin,str);
	this->_contacts[this->index].setfirstname(str);
	std::cout << "Last name: ";
	std::getline (std::cin,str);
	this->_contacts[this->index].setlastname(str);
	std::cout << "Nickname: ";
	std::getline (std::cin,str);
	this->_contacts[this->index].setnickname(str);
	std::cout << "Phone number: ";
	std::getline (std::cin,str);
	this->_contacts[this->index].setphonenumber(str);
	std::cout << "Darkest secret: ";
	std::getline (std::cin,str);
	this->_contacts[this->index].setsecret(str);
	this->index++;
}