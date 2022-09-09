/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:49:10 by fmauguin          #+#    #+#             */
/*   Updated: 2022/07/28 15:03:56 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

# define ANNOUNCE_MSG ": BraiiiiiiinnnzzzZ..."

class Zombie
{
private:
	std::string	_name;
public:
	Zombie(std::string name);
	Zombie(void);
	~Zombie(void);

	void	announce(void);
	void	setname(std::string name);
};

#endif
