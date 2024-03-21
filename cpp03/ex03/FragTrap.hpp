/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:24:14 by nuferron          #+#    #+#             */
/*   Updated: 2024/03/19 18:57:09 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap: virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string name);
		FragTrap(const FragTrap &s);
		~FragTrap();
		FragTrap	&operator=(const FragTrap &s);
		void		highFivesGuys(void) const;
	protected:
		static const unsigned int	_cth = 100;
		static const unsigned int	_cte = 100;
		static const unsigned int	_cta = 30;
};

#endif
