/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:14:01 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/27 22:18:04 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
private:

	std::string _firstname;
	std::string _lastname;
	std::string _nickname;
	std::string _phonenumber;
	std::string _darkestsecret;

public:

	Contact(void);
	~Contact(void);

	std::string	getfirstname(void) const;
	std::string	getlastname(void) const;
	std::string	getnickname(void) const;
	std::string	getphonenumber(void) const;
	std::string	getsecret(void) const;

	void		setfirstname(std::string str);
	void		setlastname(std::string str);
	void		setnickname(std::string str);
	void		setphonenumber(std::string str);
	void		setsecret(std::string str);

};

#endif
