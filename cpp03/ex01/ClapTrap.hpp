/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:45:33 by nuferron          #+#    #+#             */
/*   Updated: 2024/03/19 16:52:21 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap &c);
		~ClapTrap();
		ClapTrap		&operator=(ClapTrap &c);
		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		std::string		getName(void);
		int				getHit(void);
		int				getEnergy(void);
		int				getAttack(void);
		void			setAttack(unsigned int a);
	private:
		std::string		_name;
		unsigned int	_hit;
		unsigned int	_energy;
		unsigned int	_attack;
};

#endif
