/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:38:00 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/27 20:15:49 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

std::string	Contact::getfirstname(void) const {
	return this->_firstname;
}

void	Contact::setfirstname(std::string str) {
	this->_firstname.assign(str);
	return ;
}

std::string	Contact::getlastname(void) const {
	return this->_lastname;
}

void	Contact::setlastname(std::string str) {
	this->_lastname.assign(str);
	return ;
}

std::string	Contact::getnickname(void) const {
	return this->_nickname;
}

void	Contact::setnickname(std::string str) {
	this->_nickname.assign(str);
	return ;
}

std::string	Contact::getphonenumber(void) const {
	return this->_phonenumber;
}

void	Contact::setphonenumber(std::string str) {
	this->_phonenumber.assign(str);
	return ;
}

std::string	Contact::getsecret(void) const {
	return this->_secret;
}

void	Contact::setsecret(std::string str) {
	this->_secret.assign(str);
	return ;
}