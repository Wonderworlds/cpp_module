/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:57:21 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/28 16:05:30 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
private:
	std::string	_name;
	Weapon		_weapon;
public:
	HumanA(std::string name, Weapon weapon);
	~HumanA(void);
	void	setweapon(Weapon weapon);
	void	attack(void);
};

#endif