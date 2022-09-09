/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:50:21 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/05 15:13:48 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
	#define DEBUG_LOG(A) PRINT(A)
#else
	#define DEBUG_LOG(A)
#endif

class Data
{
private:
	int	_value;
public:
	Data(void);
	Data(int const &i);
	Data(Data const & src);
	~Data(void);

	int const & getValue(void) const;
	Data &	operator=(Data const & rhs);

};

#endif