/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:45:33 by nuferron          #+#    #+#             */
/*   Updated: 2024/03/19 16:03:46 by nuferron         ###   ########.fr       */
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
		void			setHit(unsigned int h);
		void			setEnergy(unsigned int e);
		void			setAttack(unsigned int a);
	private:
		std::string	_name;
		int			_hit;
		int			_energy;
		int			_attack;
};

#endif
