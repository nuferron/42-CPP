/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:24:14 by nuferron          #+#    #+#             */
/*   Updated: 2024/03/19 18:57:09 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &s);
		~ScavTrap();
		ScavTrap	&operator=(const ScavTrap &s);
		void		attack(const std::string &target);
		void		guardGate(void) const;
	protected:
		static const unsigned int	_cth = 100;
		static const unsigned int	_cte = 50;
		static const unsigned int	_cta = 20;
};

#endif
