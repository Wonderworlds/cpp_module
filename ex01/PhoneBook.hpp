/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:12:04 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/28 00:37:27 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {

private:
	Contact _contacts[8];
	int		_index;
	int		_size;
public:
	PhoneBook(void);
	~PhoneBook(void);
	const Contact	*getcontact(int index) const;
	void	setcontact(void);
	int		getsize(void) const;
};

#endif